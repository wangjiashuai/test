#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GameControl.h"
#include "ClientData.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default val--ue is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

//    // create a scene. it's an autorelease object
//    CCScene *pScene = HelloWorld::scene();
//
//    // run
//    pDirector->runWithScene(pScene);
    CCSize size =  pEGLView->getVisibleSize();
    CCLog("winssize with:%f height:%f",size.width,size.height);
    pEGLView->setDesignResolutionSize(1136,640, kResolutionShowAll);
    GameData::Shared()->getEnglishData();
    GameControl::Shared()->BeginGame();
    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
