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

GameListView::GameListView()
{
    m_pArrItems = new CCArray;
    m_pArrItems->init();
    
    m_curItemIndex = 0;
}

GameListView::~GameListView()
{
    CC_SAFE_RELEASE_NULL(m_pArrItems);
}

CCSize  GameListView::getPageSize()
{
    return CCSizeMake(100, 100);
}


void    GameListView::addItem(cocos2d::extension::Layout *item)
{
    m_pArrItems->addObject(item);
}

CCSize  GameListView::getItemSize()
{
    return CCSizeMake(100, 50);
}