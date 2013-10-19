//
//  GameControl.h
//  English
//
//  Created by wang jia shuai on 13-10-19.
//
//

#ifndef __English__GameControl__
#define __English__GameControl__
#include "cocos2d.h"
USING_NS_CC;

class GameControl  {
public:
    static  GameControl *Shared();
    GameControl();
    virtual     void    onUpdate(float time);
    virtual     bool    ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void        BeginGame();
    void        AddSprite(CCNode *pNode);
    void        RemoveSprite(CCNode *pNode);
    
    void        onTimeAddFlay();
    void        AddFlay();
    void        onLogic();
    CCNode*     makeSprite();
private:
    CCNode  *getFirstSelect();
    CCNode  *getSecondSelect();
    
    
    CCArray *m_pArrSprite;
    CCArray *m_pArrRemove;
    CCScene *m_pGameScene;
    CCLayer *m_pGameLayer;
    CC_SYNTHESIZE(float, m_speed,Speed);
    CC_SYNTHESIZE(float, m_spacing, Spacing)
    
    CCSize  m_winSize;
};

#endif /* defined(__English__GameControl__) */
