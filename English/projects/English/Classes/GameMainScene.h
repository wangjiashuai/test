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
    
protected:
    UILayer* m_pUILayer;
    
    CCArray*    m_pArrCheck;
    int         m_lastPage;
};



#endif /* defined(__English__GameMainScene__) */
