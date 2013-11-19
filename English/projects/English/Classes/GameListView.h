//
//  GameListView.h
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#ifndef __English__GameListView__
#define __English__GameListView__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class   GameListView : public UIPageView{
public:
    static GameListView* create();
    
    CCSize  getPageSize();
    
    void    addPage(Layout* page);
//    float   getPositionXByIndex(int idx);
//    
//    virtual void updateChildrenSize();
//    virtual void updateChildrenPosition();
};

#endif /* defined(__English__GameListView__) */
