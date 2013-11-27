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
    GameListView();
    ~GameListView();
    CCSize  getPageSize();
    
    virtual void    addItem(Layout* item);
    virtual CCSize  getItemSize();
    
    virtual bool onTouchBegan(const CCPoint &touchPoint);
    virtual void onTouchMoved(const CCPoint &touchPoint);
    virtual void onTouchEnded(const CCPoint &touchPoint);
    virtual void handleReleaseLogic(const CCPoint &touchPoint);
    
    virtual float getPositionXByIndex(int idx);
private:
    CCArray*    m_pArrItems;
    
    CC_SYNTHESIZE(int, m_curItemIndex, CurItemIndex);
};

#endif /* defined(__English__GameListView__) */
