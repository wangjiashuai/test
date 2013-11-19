//
//  GameListView.cpp
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#include "GameListView.h"
#include "cocos2d.h"
USING_NS_CC;

GameListView* GameListView::create()
{
    GameListView* widget = new GameListView();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return NULL;
}

CCSize  GameListView::getPageSize()
{
    return CCSizeMake(100, 100);
}
