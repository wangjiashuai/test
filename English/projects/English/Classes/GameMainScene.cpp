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
    
//    CCSprite *pBackSprite = CCSprite::create("res/smgrback-hd.png");
//    addChild(pBackSprite);
//    pBackSprite->setPosition(getUIPositionByWin(ccp(0.5, 0.5)));
    
    m_pUILayer = UILayer::create();
    m_pUILayer->scheduleUpdate();
    m_pUILayer->setTouchEnabled(true);
    addChild(m_pUILayer);
    
    UIImageView *pImageView = UIImageView::create();
    pImageView->setTexture("res/main_strip.png");
    m_pUILayer->addWidget(pImageView);
    pImageView->setAnchorPoint(ccp(0.5, 0.5));
    pImageView->setPosition(getUIPositionByWin(ccp(0.5, 0.5)));
    pImageView->setScale(0.8);
    
    GameListView *pPageView = GameListView::create();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    pPageView->setSize(winSize);
    //pPageView->setPosition(getUIPosition(m_pUILayer,ccp(0.5,0.5)));
    pPageView->setTouchEnable(true);
    pPageView->addPageTurningEvent(this, coco_PageView_PageTurning_selector(GameMainScene::onPageTurningEvent));
    pPageView->addEventListener(this, pagevieweventselector(GameMainScene::onPageEvent));
    m_pUILayer->addWidget(pPageView);
    
    UIImageView *pFrogImage = UIImageView::create();
    pFrogImage->setTexture("res/frog.png");
    m_pUILayer->addWidget(pFrogImage);
    pFrogImage->setPosition(getUIPositionByWin(ccp(0.2, 0.2)));
    pFrogImage->setScale(0.8);
    m_pFrogImage = pFrogImage;

    
    
    UIImageView *pUFOImage = UIImageView::create();
    pUFOImage->setTexture("res/ufo.png");
    m_pUILayer->addWidget(pUFOImage);
    pUFOImage->setPosition(getUIPositionByWin(ccp(0.5, 0.5)));
    pUFOImage->setAnchorPoint(ccp(0.5, 0.5));
    m_pUFOImage = pUFOImage;
    
    for (int i = 0; i < 10; i ++) {
        Layout *pLayout = Layout::create();
        pLayout->setSize(winSize);
        
        UIImageView *pImage = UIImageView::create();
        pImage->loadTexture("res/main_listview_item.png");
        pLayout->addChild(pImage);
        pImage->setScale(0.8);
        pImage->setPosition(getUIPosition(pLayout, ccp(0.5, 0.5)));
        
        CCLabelTTF *pTTF = CCLabelTTF::create("本关单词数", "Regular", 22);
        pLayout->addCCNode(pTTF);
        pTTF->setPosition(getUIPosition(pLayout, ccp(0.5, 0.5)));
        pTTF->setFontFillColor(ccc3(255, 241, 203));
        pTTF->enableStroke(ccc3(32, 16, 16), 1);
        
        pTTF = CCLabelTTF::create("本关难度", "Regular", 22);
        pLayout->addCCNode(pTTF);
        pTTF->setPosition(getUIPosition(pLayout, ccp(0.5, 0.55)));
        pTTF->setFontFillColor(ccc3(255, 241, 203));
        pTTF->enableStroke(ccc3(32, 16, 16), 1);
        
        pTTF = CCLabelTTF::create("是否已过", "Regular", 22);
        pLayout->addCCNode(pTTF);
        pTTF->setPosition(getUIPosition(pLayout, ccp(0.5, 0.6)));
        pTTF->setFontFillColor(ccc3(255, 241, 203));
        pTTF->enableStroke(ccc3(32, 16, 16), 1);
        
        pPageView->addItem(pLayout);
    }
    
    return true;
}

void    GameMainScene::onPageEvent(cocos2d::CCObject *pSender, int eventType)
{
    if(eventType == 0){
        m_pUFOImage->setVisible(true);
    }
    else if(eventType == 10){
        m_pUFOImage->setVisible(false);
    }
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
    UIListView* list = dynamic_cast<UIListView*>(pSender);
    
    Layout* layout = dynamic_cast<Layout*>(list->getUpdateChild());
    UITextButton* textButton = dynamic_cast<UITextButton*>(layout->getChildByName("TextButton"));
    textButton->setText("test");
    textButton->setTitleFontSize(30);
}

void    GameMainScene::updateChildEvent(cocos2d::CCObject *pSender)
{
    UIListView* list = dynamic_cast<UIListView*>(pSender);
    int index = list->getUpdateDataIndex();
    
    if (index < 0 || index >= list->getDataLength())
    {
        list->setUpdateSuccess(false);
    }
    CCLOG("index %d",index);
    Layout* layout = dynamic_cast<Layout*>(list->getUpdateChild());
    UITextButton* textButton = dynamic_cast<UITextButton*>(layout->getChildByName("TextButton"));
    CCString *pStr = CCString::createWithFormat("test %d",index);
    textButton->setText(pStr->getCString());
    list->setUpdateSuccess(true);
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
    //setCheck(page);
    
}


bool    GameMainScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void    GameMainScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
}
