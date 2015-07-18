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
#include "ICCVideoPlayerProtocol.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#ifdef __OBJC__
@class CCVideoPlayeriOS;
#endif
#endif

namespace ccvideoplayer
{
    
#ifdef __OBJC__
typedef CCVideoPlayeriOS *CCVideoPlayeriOSPtr;
#else
typedef void* CCVideoPlayeriOSPtr;
#endif

class CCVideoPlayerWrapper {
public:
    
    ~CCVideoPlayerWrapper();
    void playVideo(const char *videoPath);
    
    void setDelegate(ICCVideoPlayerProtocol* delegate);
    ICCVideoPlayerProtocol* getDelegate();
    
    static CCVideoPlayerWrapper *create();
    
private:
    bool init();
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    CCVideoPlayeriOSPtr _player;
#endif
};
    
}

#endif /* defined(__Farmer__WrapperClass__) */
