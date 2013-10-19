//
//  MainGameLayer.h
//  English
//
//  Created by wangjiashuai on 17/10/13.
//
//


#ifndef __English__MainGameLayer__
#define __English__MainGameLayer__
#include "cocos2d.h"
USING_NS_CC;

class MainGameLayer : public  CCLayer{
public:
    CREATE_FUNC(MainGameLayer);
    
    MainGameLayer();
    virtual bool        init();
    virtual void        onUpdate(float time);
    virtual bool        ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void        ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
};

#endif /* defined(__English__MainGameLayer__) */
