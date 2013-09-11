//
//  WrapperClass.cpp
//  Farmer
//
//  Created by saiy2k on 07/09/13.
//
//

#include "WrapperClass.h"
#include "AudioManager.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "iOSWrapper.h"
#endif

static WrapperClass *instance   =   NULL;

void WrapperClass::playVideo(const char *vidPath) {
    AudioManager::sharedManager()->stopBG();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    iOSWrapper::getShared()->playVideo(vidPath);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    CCApplication::sharedApplication()->playVideo();
#endif
}

WrapperClass *WrapperClass::getShared() {
    if (!instance) {
        instance                =   new WrapperClass();
    }
    return                          instance;
}