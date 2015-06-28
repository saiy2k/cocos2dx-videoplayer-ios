//
//  CCVideoPlayerWrapper.cpp
//  Farmer
//
//  Created by saiy2k on 07/09/13.
//
//

#include "CCVideoPlayerWrapper.h"
#include "AudioManager.h"

using namespace ccvideoplayer;

void CCVideoPlayerWrapper::playVideo(const char *vidPath) {
    // stop bg music first before playing video
    AudioManager::sharedManager()->stopBG();
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    CCVideoPlayeriOS::getSharedInstance()->playVideo(vidPath);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    // not yet implemented ...
    // the line here is just placeholder
    CCApplication::sharedApplication()->playVideo();
#endif
}

CCVideoPlayerWrapper *CCVideoPlayerWrapper::getSharedInstance() {
    static CCVideoPlayerWrapper *sharedInstance;
    if(sharedInstance == NULL)
    {
        sharedInstance = new CCVideoPlayerWrapper();
    }
    return sharedInstance;
}