#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CCVideoPlayer.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace ccvideoplayer;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCMenuItemFont *vidFont = CCMenuItemFont::create("Click to play Video", this, menu_selector(HelloWorld::menuCallback));
    
    CCMenu* pMenu = CCMenu::create(vidFont, NULL);
    //pMenu->setPosition( ccp(c->screenWidth * 0.5, c->screenHeight * 0.5) );
    this->addChild(pMenu, 1);
    
    return true;
}

void HelloWorld::menuCallback(CCObject* pSender)
{
    CCVideoPlayer::sharedInstance()->playVideo("sampleVideo");
}
