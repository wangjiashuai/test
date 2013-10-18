//
//  MainGameLayer.h
//  English
//
//  Created by wangjiashuai on 17/10/13.
//
//
#include "cocos2d.h"

#ifndef __English__MainGameLayer__
#define __English__MainGameLayer__
USING_NS_CC;

class MainGameLayer : public  CCLayer{
public:
    CREATE_FUNC(MainGameLayer);
    
    virtual bool        init();
    virtual void        onUpdate(float time);
};

#endif /* defined(__English__MainGameLayer__) */
