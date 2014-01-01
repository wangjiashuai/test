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

CCGLProgram*    getTextShader()
{
    CCGLProgram *pProgram = CCShaderCache::sharedShaderCache()->programForKey("TextShader");
    if(pProgram){
        return pProgram;
    }
    pProgram = new CCGLProgram;
    pProgram->initWithVertexShaderFilename("res/textVShaer", "res/textFShaer");
    CCShaderCache::sharedShaderCache()->addProgram(pProgram, "TextShader");
    pProgram->addAttribute("inputImageTexture", kCCVertexAttrib_TexCoords);
    pProgram->link();
    pProgram->updateUniforms();
    pProgram->autorelease();
    return pProgram;
}

CCRenderTexture* createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity)
{
    CCRenderTexture* rt = CCRenderTexture::create(label->getTexture()->getContentSize().width + size*2, label->getTexture()->getContentSize().height + size*2);
    CCPoint originalPos = label->getPosition();
    ccColor3B originalColor = label->getColor();
    bool originalVisibility = label->isVisible();
    
    label->setColor(color);
    label->setVisible(true);
    
    ccBlendFunc originalBlend = label->getBlendFunc();
    label->setBlendFunc((ccBlendFunc){ GL_SRC_ALPHA, GL_ONE });
    
    CCPoint bottomLeft = ccp(label->getTexture()->getContentSize().width*label->getAnchorPoint().x + size, label->getTexture()->getContentSize().height*label->getAnchorPoint().y + size);
    CCPoint positionOffset = ccp(label->getTexture()->getContentSize().width*label->getAnchorPoint().x - label->getTexture()->getContentSize().width/2, label->getTexture()->getContentSize().height*label->getAnchorPoint().y - label->getTexture()->getContentSize().height/2);
    CCPoint position = ccpSub(originalPos, positionOffset);
    
    rt->begin();
    for (int i = 0; i<360; i+=30) {
        label->setPosition(ccp(bottomLeft.x + sin(CC_DEGREES_TO_RADIANS(i))*size,bottomLeft.y + cos(CC_DEGREES_TO_RADIANS(i))*size));
        label->visit();
    }
    rt->end();
    label->setPosition(originalPos);
    label->setColor(originalColor);
    label->setBlendFunc(originalBlend);
    label->setVisible(originalVisibility);
    rt->setPosition(position);
    return rt;
}