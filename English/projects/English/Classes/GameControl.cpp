//
//  GameControl.cpp
//  English
//
//  Created by wang jia shuai on 13-10-19.
//
//

#include "GameControl.h"
#include "MainGameLayer.h"
#include "GameSprite_Flay.h"
#include "ClientData.h"
#include "GameMainScene.h"

GameControl *g_pGameControl = NULL;
GameControl *GameControl::Shared()
{
    if(!g_pGameControl){
        g_pGameControl = new GameControl;
    }
    
    return g_pGameControl;
}

GameControl::GameControl()
{
    m_pArrSprite = new CCArray;
    m_pArrSprite->init();
    m_pArrRemove = new CCArray;
    m_pArrRemove->init();
    m_speed = 50;
    m_spacing = 100;
    m_bPause = false;
    
    m_winSize = CCDirector::sharedDirector()->getWinSize();
}

void    GameControl::onUpdate(float time)
{
    CCObject *pObject = NULL;
    GameSprite_Flay *pFlay = NULL;
    float addPos = m_speed * time;
    
    if(!m_bPause){
        CCPoint curPos;
        CCSize spriteSize;
        CCARRAY_FOREACH(m_pArrSprite, pObject){
            pFlay = (GameSprite_Flay*)pObject;
            curPos = pFlay->getPosition();
            curPos.x -= addPos;
            pFlay->setPosition(curPos);
            spriteSize = pFlay->getContentSize();
            if(curPos.x < spriteSize.width * -1){
                m_pArrRemove->addObject(pObject);
            }
        }
        
        CCARRAY_FOREACH(m_pArrRemove, pObject){
            
            pFlay = (GameSprite_Flay*)pObject;
            RemoveSprite(pFlay);
            Pause();
        }
    }

    
    onTimeAddFlay();
    onLogic();
}

void    GameControl::AddSprite(cocos2d::CCNode *pNode)
{
    m_pArrSprite->addObject(pNode);
    m_pGameLayer->addChild(pNode);
}

void    GameControl::RemoveSprite(cocos2d::CCNode *pNode)
{
    m_pArrSprite->removeObject(pNode);
    m_pGameLayer->removeChild(pNode);
}

bool    GameControl::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchPostion = pTouch->getLocation();
    CCObject *pObject = NULL;
    GameSprite_Flay *pFlay = NULL;
    CCPoint curPos;
    CCRect spriteRect;
    CCARRAY_FOREACH(m_pArrSprite, pObject){
        pFlay = (GameSprite_Flay*)pObject;
        spriteRect.size = pFlay->getContentSize();
        spriteRect.origin = pFlay->getPosition();
        spriteRect.origin.x = spriteRect.origin.x - spriteRect.size.width * pFlay->getAnchorPoint().x;
        spriteRect.origin.y = spriteRect.origin.y - spriteRect.size.height * pFlay->getAnchorPoint().y;
        if(spriteRect.containsPoint(touchPostion)){
            pFlay->setSelectState();
        }
    }
    
    return true;
}

void    GameControl::BeginGame()
{
    m_pGameScene = CCScene::create();
    
    GameMainScene *pNode = GameMainScene::create();
    pNode->setTouchEnabled(true);
    m_pGameLayer = pNode;
    m_pGameScene->addChild(pNode);
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->runWithScene(m_pGameScene);
    
}

void    GameControl::Pause()
{
    m_bPause = true;
}

void    GameControl::onTimeAddFlay()
{
    GameSprite_Flay *pFlay = (GameSprite_Flay*)m_pArrSprite->lastObject();
    if(pFlay){
        float condition = m_winSize.width - m_spacing;
        CCPoint curPosition = pFlay->getPosition();
        if(curPosition.x <= condition){
            AddFlay();
        }
    }
    else{
        AddFlay();
    }
}

void    GameControl::AddFlay()
{
    float addHeight = m_winSize.height / 5;
    GameSprite_Flay *pFlay = (GameSprite_Flay*)makeSprite();
    AddSprite(pFlay);
    
    CCSize spriteSize = pFlay->getContentSize();
    CCPoint setPos = ccp(m_winSize.width + spriteSize.width / 2,addHeight);
    pFlay->setPosition(setPos);
    pFlay->setAnchorPoint(ccp(0.5,0.5));
    
    setPos.y += addHeight;
    pFlay = (GameSprite_Flay*)makeSprite();
    AddSprite(pFlay);
    pFlay->setPosition(setPos);
    pFlay->setAnchorPoint(ccp(0.5,0.5));

    setPos.y += addHeight;
    pFlay = (GameSprite_Flay*)makeSprite();
    AddSprite(pFlay);
    pFlay->setPosition(setPos);
    pFlay->setAnchorPoint(ccp(0.5,0.5));
    
    setPos.y += addHeight;
    pFlay = (GameSprite_Flay*)makeSprite();
    AddSprite(pFlay);
    pFlay->setPosition(setPos);
    pFlay->setAnchorPoint(ccp(0.5,0.5));
}

void    GameControl::onLogic()
{
    GameSprite_Flay *pFlay1 = (GameSprite_Flay*)getFirstSelect();
    if(pFlay1){
        GameSprite_Flay *pFlay2 = (GameSprite_Flay*)getSecondSelect();
        if(pFlay2){
            if(pFlay1->getSpriteID() == pFlay2->getSpriteID()){
                //RemoveSprite(pFlay1);
                //RemoveSprite(pFlay2);
                pFlay1->removeFromGame();
                pFlay2->removeFromGame();
            }
            else{
                pFlay1->removeSelectState();
                pFlay2->removeSelectState();
            }
        }
    }
}

CCNode*    GameControl::getFirstSelect()
{
    CCObject *pObject = NULL;
    GameSprite_Flay *pFlay = NULL;
    CCARRAY_FOREACH(m_pArrSprite, pObject){
        pFlay = (GameSprite_Flay*)pObject;
        if(pFlay){
            if(pFlay->getBSelect() && !pFlay->getBRemove()){
                return pFlay;
            }
        }
    }
    
    return NULL;
}

CCNode*    GameControl::getSecondSelect()
{
    CCObject *pObject = NULL;
    GameSprite_Flay *pFlay = NULL;
    bool b = false;
    CCARRAY_FOREACH(m_pArrSprite, pObject){
        pFlay = (GameSprite_Flay*)pObject;
        if(pFlay){
            if(pFlay->getBSelect() && !pFlay->getBRemove()){
                if(b){
                    return pFlay;
                }
                b = true;
            }
        }
    }
    
    return NULL;
}

CCNode*    GameControl::makeSprite()
{
    GameData *pGameData = GameData::Shared();
    int maxCount = pGameData->getEnlishCount();
    
    GameSprite_Flay *pFlay = GameSprite_Flay::create();
    int rValue = arc4random();
    int rKeyIndex = abs(rValue) % maxCount;
    const char *pKey = pGameData->getEnglishKeyName(rKeyIndex);
    pFlay->setSpriteID(rKeyIndex);
    rValue = arc4random();
    if(rValue % 2){
        pFlay->setCharacterEN(pKey);
    }
    else{
        const char *pKeyData = pGameData->getEnglishKeyData(rKeyIndex);
        pFlay->setCharacterEN(pKeyData);
    }
    
    return pFlay;
}
