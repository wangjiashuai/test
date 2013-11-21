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
    return CCSizeMake(100, 100);
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
    CCSize pSize = page->getSize();
    CCSize pvSize = getPageSize();
    if (!pSize.equals(pvSize))
    {
        CCLOG("page size does not match pageview size, it will be force sized!");
        item->setSize(pvSize);
    }
    item->setPosition(ccp(getPositionXByIndex(m_pages->count()), 0));
    m_pages->addObject(item);
    addChild(item);
    updateBoundaryPages();
}

CCSize  GameListView::getItemSize()
{
    return CCSizeMake(100, 50);
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
