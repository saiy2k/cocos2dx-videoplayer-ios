//
//  CCVideoPlayerWrapper.h
//  Farmer
//
//  Created by saiy2k on 07/09/13.
//
//

#ifndef __Farmer__CCVideoPlayerWrapper__
#define __Farmer__CCVideoPlayerWrapper__

#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "CCVideoPlayeriOS.h"
#endif

using namespace cocos2d;

namespace ccvideoplayer
{

class CCVideoPlayerWrapper : public cocos2d::CCObject {
public:
    
    void playVideo(const char *vidPath);
    
    static CCVideoPlayerWrapper *getSharedInstance();
};
    
}

#endif /* defined(__Farmer__WrapperClass__) */
