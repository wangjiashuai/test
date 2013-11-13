//
//  GameListView.h
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#ifndef __English__GameListView__
#define __English__GameListView__
#include "cocos-ext.h"
USING_NS_CC_EXT;

class   GameListView : public UIListView{
public:
    static GameListView* create();
    
    virtual void endRecordSlidAction();
};

#endif /* defined(__English__GameListView__) */
