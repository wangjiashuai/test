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

void    GameListView::endRecordSlidAction()
{
    UIListView::endRecordSlidAction();
    
    int updateIndex = getUpdateDataIndex();
    CCLOG("endRecordSlidAction %d",updateIndex);
    if(m_eMoveDirection == LISTVIEW_MOVE_DIR_LEFT){
        updateIndex = updateIndex - 1;
    }
    else{
        updateIndex = updateIndex + 1;
    }
    
    ccArray* arrayChildren = m_children->data;
    UIWidget* child = (UIWidget*)(arrayChildren->arr[2]);
    
    CCPoint curPos = child->getPosition();
    curPos.x = 200 - curPos.x;
    this->stopAutoScrollChildren();
    scrollChildren(curPos.x);

    
}