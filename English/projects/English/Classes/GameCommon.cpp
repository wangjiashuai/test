//
//  GameCommon.cpp
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#include "GameCommon.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

CCPoint  getUIPosition(CCObject *pParentNode,const CCPoint &relativePT)
{
    CCSize size;
    if(dynamic_cast<UIWidget*>(pParentNode)){
        UIWidget *pWidget = (UIWidget*)pParentNode;
        size = pWidget->getRect().size;
    }
    else{
        CCNode *pNode = (CCNode*)pParentNode;
        size = pNode->getContentSize();
    }
    
    CCPoint returnPT = ccp(size.width * relativePT.x,size.height * relativePT.y);
    return returnPT;
}

CCSize   getUIPositionByWin(const CCPoint &relativePT)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint returnPT = ccp(winSize.width * relativePT.x,winSize.height * relativePT.y);
    return returnPT;
}