//
//  GameCommon.h
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#ifndef __English__GameCommon__
#define __English__GameCommon__
#include "cocos2d.h"
USING_NS_CC;

CCPoint  getUIPosition(CCObject *pParentNode,const CCPoint &relativePT);
CCSize   getUIPositionByWin(const CCPoint &relativePT);

#endif /* defined(__English__GameCommon__) */
