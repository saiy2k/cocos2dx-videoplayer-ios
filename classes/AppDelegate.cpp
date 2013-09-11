//
//  VideoPlayerAppDelegate.cpp
//  VideoPlayer
//
//  Created by saiy2k on 11/09/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "AudioManager.h"
#include "Config.h"
#include "HelloWorldScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(true);
    Config::getConfig()->screenWidth = CCEGLView::sharedOpenGLView()->getFrameSize().width;
    Config::getConfig()->screenHeight = CCEGLView::sharedOpenGLView()->getFrameSize().height;
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(Config::getConfig()->screenWidth,
                                                           Config::getConfig()->screenHeight,
                                                           kResolutionShowAll);
    pDirector->setContentScaleFactor(1536.0 / CCEGLView::sharedOpenGLView()->getFrameSize().height);
    pDirector->setAnimationInterval(1.0 / 60);

    AudioManager::sharedManager()->playBG();
    
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
