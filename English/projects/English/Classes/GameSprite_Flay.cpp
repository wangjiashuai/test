//
//  GameSprite_Flay.cpp
//  English
//
//  Created by wang jia shuai on 13-10-19.
//
//

#include "GameSprite_Flay.h"

GameSprite_Flay *GameSprite_Flay::create()
{
    GameSprite_Flay *pobSprite = new GameSprite_Flay();
    if (pobSprite && pobSprite->initWithFile("res/spriteback.png"))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

GameSprite_Flay::GameSprite_Flay()
{
    m_bSelect = false;
    m_SpriteID = 0;
    m_bRemove = false;
    m_bEnglish = false;
    //m_Speed = 0;
}


void    GameSprite_Flay::setSelectState()
{
    if(getChildByTag(1)){
        return;
    }
    
    CCSprite *pSprite = CCSprite::create("res/spriteselect.png");
    addChild(pSprite,0,1);
    pSprite->setAnchorPoint(ccp(0.5, 0.5));
    
    CCSize size = getContentSize();
    pSprite->setPosition(ccp(size.width/2, size.height/2));
    setBSelect(true);
}

void    GameSprite_Flay::removeSelectState()
{
    removeChildByTag(1);
    setBSelect(false);
}

void    GameSprite_Flay::removeFromGame()
{
    setBRemove(true);
    flipX();
    scale();
}

void    GameSprite_Flay::setCharacterCN(const char *pCN)
{
    CCLabelTTF *pTTF = CCLabelTTF::create(pCN, "Marker Fel", 20);
    addChild(pTTF);
    CCSize size = getContentSize();
    pTTF->setPosition(ccp(size.width/2, size.height/2));
}

void    GameSprite_Flay::setCharacterEN(const char *pEN)
{
    CCLabelTTF *pTTF = CCLabelTTF::create(pEN, "Marker Fel", 20);
    addChild(pTTF);
    CCSize size = getContentSize();
    pTTF->setPosition(ccp(size.width/2, size.height/2));
}