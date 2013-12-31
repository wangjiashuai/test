//
//  GameListView.cpp
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#include "GameListView.h"
#include "cocos2d.h"
USING_NS_CC;

GameListView* GameListView::create()
{
    GameListView* widget = new GameListView();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return NULL;
}

GameListView::GameListView()
{
    m_pArrItems = new CCArray;
    m_pArrItems->init();
    
    m_curItemIndex = 0;
}

GameListView::~GameListView()
{
    CC_SAFE_RELEASE_NULL(m_pArrItems);
}

CCSize  GameListView::getPageSize()
{
    return CCSizeMake(300, 100);
}

void    GameListView::addItem(cocos2d::extension::Layout *item)
{
    m_pArrItems->addObject(item);
    
    if (!item)
    {
        return;
    }
    if (item->getWidgetType() != WidgetTypeContainer)
    {
        return;
    }
    if (m_pages->containsObject(item))
    {
        return;
    }
    CCSize pSize = item->getSize();
    CCSize pvSize = getPageSize();
    if (!pSize.equals(pvSize))
    {
        CCLOG("page size does not match pageview size, it will be force sized!");
        item->setSize(pvSize);
    }
    
    CCPoint setPosition = ccp(getPositionXByIndex(m_pages->count()), 0);
    CCLOG("setPosition x:%f",setPosition.x);
    item->setPosition(setPosition);
    m_pages->addObject(item);
    addChild(item);
    updateBoundaryPages();
}

CCSize  GameListView::getItemSize()
{
    return CCSizeMake(300, 50);
}

bool GameListView::onTouchBegan(const CCPoint &touchPoint)
{
    bool pass = Layout::onTouchBegan(touchPoint);
    handlePressLogic(touchPoint);
    return pass;
}

void GameListView::onTouchMoved(const CCPoint &touchPoint)
{
    m_touchMovePos.x = touchPoint.x;
    m_touchMovePos.y = touchPoint.y;
    handleMoveLogic(touchPoint);
    if (m_pWidgetParent)
    {
        m_pWidgetParent->checkChildInfo(1,this,touchPoint);
    }
    moveEvent();
    if (!hitTest(touchPoint))
    {
        setFocused(false);
        onTouchEnded(touchPoint);
    }
}

void GameListView::onTouchEnded(const CCPoint &touchPoint)
{
    Layout::onTouchEnded(touchPoint);
    handleReleaseLogic(touchPoint);
}

float   GameListView::getPositionXByIndex(int idx)
{
    return (getPageSize().width*(idx-m_nCurPageIdx));
}

void    GameListView::onSizeChanged()
{
    UIPageView::onSizeChanged();
    
    m_fLeftBoundary = getSize().width * 0.3;
}

void GameListView::handleReleaseLogic(const CCPoint &touchPoint)
{
    UIWidget* curPage = dynamic_cast<UIWidget*>(m_pages->objectAtIndex(m_nCurPageIdx));
    if (curPage)
    {
        CCPoint curPagePos = curPage->getPosition();
        int pageCount = m_pages->count();
        float curPageLocation = curPagePos.x;
        float pageWidth = getSize().width;
        float boundary = pageWidth * 0.1;
        CCLOG("pageWidth %f boundary %f",pageWidth,boundary);
        if (curPageLocation <= -boundary)
        {
            if (m_nCurPageIdx >= pageCount-1)
            {
                scrollPages(-curPageLocation);
            }
            else
            {
                scrollToPage(m_nCurPageIdx+1);
            }
        }
        else if (curPageLocation >= boundary)
        {
            if (m_nCurPageIdx <= 0)
            {
                scrollPages(-curPageLocation);
            }
            else
            {
                scrollToPage(m_nCurPageIdx-1);
            }
        }
        else
        {
            scrollToPage(m_nCurPageIdx);
        }
    }
}

bool GameListView::scrollPages(float touchOffset)
{
    if (m_pages->count() <= 0)
    {
        return false;
    }
    
    if (!m_pLeftChild || !m_pRightChild)
    {
        return false;
    }
    
    float realOffset = touchOffset;
    
    switch (m_touchMoveDir)
    {
        case PAGEVIEW_TOUCHLEFT: // left
            if (m_pRightChild->getRightInParent() + touchOffset <= 0)
            {
                realOffset = 0 - m_pRightChild->getRightInParent();
                movePages(realOffset);
                return false;
            }
            break;
            
        case PAGEVIEW_TOUCHRIGHT: // right
            CCLOG("scrollpages offset:%f",m_pLeftChild->getLeftInParent() + touchOffset);
            if (m_pLeftChild->getLeftInParent() + touchOffset >= m_fLeftBoundary)
            {
                realOffset = m_fLeftBoundary - m_pLeftChild->getLeftInParent();
                movePages(realOffset);
                return false;
            }
            break;
        default:
            break;
    }
    
    movePages(realOffset);
    return true;
}