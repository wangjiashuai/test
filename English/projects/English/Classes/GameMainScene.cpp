//
//  GameMainScene.cpp
//  English
//
//  Created by wangjiashuai on 8/11/13.
//
//

#include "GameMainScene.h"
#include "GameCommon.h"
#include "GameListView.h"

#define RES_PAGECHECK_BACK "res/check01.png"
#define RES_PAGECHECK_CHECK "res/check.png"
GameMainScene::GameMainScene()
{
    m_pArrCheck = new CCArray;
    m_pArrCheck->init();
    
    m_lastPage = 0;
}

GameMainScene::~GameMainScene()
{
    CC_SAFE_DELETE(m_pArrCheck);
}

bool    GameMainScene::init()
{
    CCLayer::init();
    
    CCSprite *pBackSprite = CCSprite::create("res/smgrback-hd.png");
    addChild(pBackSprite);
    pBackSprite->setPosition(getUIPositionByWin(ccp(0.5, 0.5)));
    
    m_pUILayer = UILayer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    GameListView *listView = GameListView::create();
    listView->setDirection(LISTVIEW_DIR_HORIZONTAL);
    listView->setTouchEnabled(true);
    listView->setSize(CCSizeMake(240, 130));
    listView->setColor(ccRED);
    listView->setBackGroundColor(ccRED);
    m_pUILayer->addWidget(listView);
    
    for (int i = 0; i < 3; ++i)
    {
        UITextButton* textButton = UITextButton::create();
        textButton->setName("TextButton");
        textButton->setTouchEnabled(true);
        textButton->loadTextures("cocosgui/backtotoppressed.png", "cocosgui/backtotopnormal.png", "");
        
        Layout *layout = Layout::create();
        layout->setName(CCString::createWithFormat("panel_%i", i)->getCString());
        layout->setSize(CCSizeMake(textButton->getRect().size.width, textButton->getRect().size.height));
        textButton->setPosition(ccp(layout->getRect().size.width / 2, layout->getRect().size.height / 2));
        layout->addChild(textButton);
        
        CCSize layout_size = layout->getRect().size;
        layout->setPosition(ccp(0 + (layout_size.width * 0.2) + i * (layout_size.width + layout_size.width * 0.2),
                                (listHeight - layout_size.height) / 2));
        
        listView->addChild(layout);
    }
    
    listView->addInitChildEvent(this, coco_ListView_InitChild_selector(GameMainScene::initChildEvent));
    listView->addUpdateChildEvent(this, coco_ListView_UpdateChild_selector(GameMainScene::updateChildEvent));
    
    
    return true;
}

void    GameMainScene::initCheckItem(int num)
{
    Layout *pLayout = Layout::create();
    CCSize setSize = CCSizeMake(500, 80);
    pLayout->setSize(setSize);
    pLayout->setPosition(getUIPositionByWin(ccp(0.5, 0.2)));
    pLayout->setAnchorPoint(ccp(0.5, 0.5));
    m_pUILayer->addWidget(pLayout);
    
    CCPoint juli;
    juli.x = setSize.width / num;
    CCPoint beginPT = ccp(juli.x / 2,0);
    
    for (int i = 0; i < num; i ++) {
        UIImageView *pImage = UIImageView::create();
        if(i == 0){
            pImage->setTexture(RES_PAGECHECK_CHECK);
        }
        else{
            pImage->setTexture(RES_PAGECHECK_BACK);
        }
        
        pLayout->addChild(pImage);
        pImage->setPosition(ccpAdd(beginPT, ccpMult(juli, i)));
        m_pArrCheck->addObject(pImage);
    }
}

void    GameMainScene::initChildEvent(cocos2d::CCObject *pSender)
{
    
}

void    GameMainScene::updateChildEvent(cocos2d::CCObject *pSender)
{
    
}

void    GameMainScene::setCheck(int index)
{
    UIImageView *pImage = (UIImageView*)m_pArrCheck->objectAtIndex(m_lastPage);
    if(pImage){
        pImage->setTexture(RES_PAGECHECK_BACK);
    }
    pImage = (UIImageView*)m_pArrCheck->objectAtIndex(index);
    if(pImage){
        pImage->setTexture(RES_PAGECHECK_CHECK);
    }
    m_lastPage = index;
}

void    GameMainScene::onButton(cocos2d::CCObject *sender)
{

}

void    GameMainScene::onPageTurningEvent(cocos2d::CCObject *pSender)
{
    UIPageView *pPageView = (UIPageView*)pSender;
    int page = pPageView->getPage();
    setCheck(page);
}
