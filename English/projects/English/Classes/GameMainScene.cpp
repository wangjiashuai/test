//
//  GameMainScene.cpp
//  English
//
//  Created by wangjiashuai on 8/11/13.
//
//

#include "GameMainScene.h"
#include "GameCommon.h"
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
    
    UIPageView *pPageView = UIPageView::create();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    pPageView->setSize(winSize);
    //pPageView->setPosition(getUIPosition(m_pUILayer,ccp(0.5,0.5)));
    pPageView->setTouchEnable(true);
    pPageView->setBackGroundColor(ccRED);
    pPageView->setColor(ccRED);
    pPageView->addPageTurningEvent(this, coco_PageView_PageTurning_selector(GameMainScene::onPageTurningEvent));
    
    m_pUILayer->addWidget(pPageView);
    
    for (int i = 0; i < 3; i ++) {
        Layout *pLayout = Layout::create();
        pLayout->setSize(winSize);
        
        UIImageView *pImage = UIImageView::create();
        pImage->loadTexture("res/spriteback.png");
        pLayout->addChild(pImage);
        pImage->setPosition(getUIPosition(pLayout, ccp(0.5, 0.5)));
        
        UIButton *pButton = UIButton::create();
        pButton->setTouchEnable(true);
        pButton->setTextures("res/spriteback.png", "res/spriteback.png", NULL);
        pButton->addReleaseEvent(this, coco_releaseselector(GameMainScene::onButton));
        pButton->setPosition(getUIPosition(pLayout, ccp(0.25, 0.5)));
        pLayout->addChild(pButton);
        
        
        pButton = UIButton::create();
        pButton->setTouchEnable(true);
        pButton->setTextures("res/spriteback.png", "res/spriteback.png", NULL);
        pButton->addReleaseEvent(this, coco_releaseselector(GameMainScene::onButton));
        pButton->setPosition(getUIPosition(pLayout, ccp(0.5, 0.5)));
        pLayout->addChild(pButton);
        
        pButton = UIButton::create();
        pButton->setTouchEnable(true);
        pButton->setTextures("res/spriteback.png", "res/spriteback.png", NULL);
        pButton->addReleaseEvent(this, coco_releaseselector(GameMainScene::onButton));
        pButton->setPosition(getUIPosition(pLayout, ccp(0.75, 0.5)));
        pLayout->addChild(pButton);
        
        pPageView->addPage(pLayout);
    }
    
    initCheckItem();
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
