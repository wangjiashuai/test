//
//  MainGameLayer.cpp
//  English
//
//  Created by wangjiashuai on 17/10/13.
//
//

#include "MainGameLayer.h"
#include "GameControl.h"

MainGameLayer::MainGameLayer()
{

}

bool    MainGameLayer::init()
{
    CCLayer::init();
    
    schedule(schedule_selector(MainGameLayer::onUpdate));
    
    CCSprite *pSprite = CCSprite::create("res/smgrback-hd.png");
    addChild(pSprite);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint pos = ccp(size.width * 0.5,size.height * 0.5);
    pSprite->setPosition(pos);
    return true;
}

void    MainGameLayer::onUpdate(float time)
{
    GameControl::Shared()->onUpdate(time);
}

bool    MainGameLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    GameControl::Shared()->ccTouchBegan(pTouch, pEvent);
    return true;
}

void    MainGameLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter ++) {
        GameControl::Shared()->ccTouchBegan((CCTouch*)(*iter), pEvent);
    }
    
}