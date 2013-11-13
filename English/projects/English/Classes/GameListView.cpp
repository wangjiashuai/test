//
//  GameListView.cpp
//  English
//
//  Created by wang jia shuai on 13-11-10.
//
//

#include "GameListView.h"

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

void    GameListView::endRecordSlidAction()
{
    UIListView::endRecordSlidAction();
}