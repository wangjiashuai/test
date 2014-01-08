//
//  GameMainScene.h
//  English
//
//  Created by wangjiashuai on 8/11/13.
//
//

#ifndef __English__GameMainScene__
#define __English__GameMainScene__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class GameMainScene : public CCLayer {
public:
    CREATE_FUNC(GameMainScene);
    
    GameMainScene();
    ~GameMainScene();
    virtual bool init();
    void    initCheckItem(int num = 3);
    void    setCheck(int index);
    
    void    onButton(CCObject *sender);
    void    onPageTurningEvent(CCObject* pSender);
    void    initChildEvent(CCObject* pSender);
    void    updateChildEvent(CCObject* pSender);
    void    onPageEvent(CCObject *pSender,int eventType);
    void    onItemButtonEvent(CCObject *pSener);
    
    virtual bool        ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void        ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
protected:
    UILayer* m_pUILayer;
    
    CCArray*    m_pArrCheck;
    int         m_lastPage;
    
    UIImageView*    m_pFrogImage;
    UIImageView*    m_pUFOImage;
};



#endif /* defined(__English__GameMainScene__) */
