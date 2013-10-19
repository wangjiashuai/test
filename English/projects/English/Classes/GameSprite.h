//
//  GameSprite.h
//  English
//
//  Created by wangjiashuai on 17/10/13.
//
//


#ifndef __English__GameSprite__
#define __English__GameSprite__
#include "cocos2d.h"
USING_NS_CC;

class GameSprite : public CCSprite {
public:
    CREATE_FUNC(GameSprite);

    GameSprite();
    
    void    flipX();
    void    flipY();
    void    scale();
};

#endif /* defined(__English__GameSprite__) */
