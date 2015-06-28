//
//  CCVideoPlayer.h
//  VideoPlayer
//
//  Created by haxpor on 6/28/15.
//
//

#ifndef __VideoPlayer__CCVideoPlayer__
#define __VideoPlayer__CCVideoPlayer__

#include "CCVideoPlayerWrapper.h"

namespace ccvideoplayer
{

class CCVideoPlayer
{
public:
    ~CCVideoPlayer();
    
    void playVideo(const char* videoPath);
    
    static CCVideoPlayer* sharedInstance();
    
private:
    bool init();
    ccvideoplayer::CCVideoPlayerWrapper *_internalPlayer;
};
    
}

#endif /* defined(__VideoPlayer__CCVideoPlayer__) */
