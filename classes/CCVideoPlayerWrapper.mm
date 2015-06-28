//
//  CCVideoPlayerWrapper.mm
//  Farmer
//
//  Created by saiy2k on 07/09/13.
//
//

#include "CCVideoPlayerWrapper.h"
#include "CCVideoPlayeriOS.h"
#include "SimpleAudioEngine.h"

using namespace ccvideoplayer;
using namespace CocosDenshion;

CCVideoPlayerWrapper::~CCVideoPlayerWrapper()
{
    if(_player)
    {
        [_player release];
        _player = nil;
    }
}

bool CCVideoPlayerWrapper::init()
{
    _player = [CCVideoPlayeriOS create];
    [_player retain];
    
    return true;
}

void CCVideoPlayerWrapper::playVideo(const char *videoPath) {
    // pause bg music
    CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    [_player playVideo:[NSString stringWithUTF8String:videoPath]];
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    // not yet implemented ...
    // the line here is just placeholder
    CCApplication::sharedApplication()->playVideo();
#endif
}

CCVideoPlayerWrapper *CCVideoPlayerWrapper::create() {
    // create shared instance of this object
    CCVideoPlayerWrapper *instance = new CCVideoPlayerWrapper();
    if(instance && instance->init())
    {
        // all done, will return next
    }
    else
    {
        delete instance;
        instance = NULL;
    }
    
    return instance;
}