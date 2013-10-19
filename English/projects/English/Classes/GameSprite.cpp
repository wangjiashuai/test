//
//  GameSprite.cpp
//  English
//
//  Created by wangjiashuai on 17/10/13.
//
//

#include "GameSprite.h"

GameSprite::GameSprite()
{
}

void    GameSprite::flipX()
{
    CCOrbitCamera *pCamera = CCOrbitCamera::create(1, 1, 0, 0, 180, 0, 0);
    CCHide *pHide = CCHide::create();
    CCSequence *pSeq = CCSequence::createWithTwoActions(pCamera, pHide);
    runAction(pSeq);
}

void    GameSprite::flipY()
{
    CCOrbitCamera *pCamera = CCOrbitCamera::create(1, 1, 0, 0, 180, 0, 0);
    CCHide *pHide = CCHide::create();
    CCSequence *pSeq = CCSequence::createWithTwoActions(pCamera, pHide);
    runAction(pSeq);
}

void    GameSprite::scale()
{
    CCScaleTo *pScale = CCScaleTo::create(1, 0);
    runAction(pScale);
}