//
//  CCVideoPlayer.cpp
//  VideoPlayer
//
//  Created by haxpor on 6/28/15.
//
//

#include "CCVideoPlayer.h"

using namespace ccvideoplayer;

CCVideoPlayer::~CCVideoPlayer()
{
    CC_SAFE_DELETE(_internalPlayer);
}

bool CCVideoPlayer::init()
{
    // create internal player
    _internalPlayer = CCVideoPlayerWrapper::create();
    
    return true;
}

void CCVideoPlayer::playVideo(const char* videoPath)
{
    _internalPlayer->playVideo(videoPath);
}

CCVideoPlayer* CCVideoPlayer::sharedInstance()
{
    static CCVideoPlayer *sharedInstance;
    if(sharedInstance == NULL)
    {
        sharedInstance = new CCVideoPlayer();
        if(sharedInstance && sharedInstance->init())
        {
            // all done, will return next
        }
        else
        {
            delete sharedInstance;
            sharedInstance = NULL;
        }
    }
    
    return sharedInstance;
}

void CCVideoPlayer::setDelegate(ICCVideoPlayerProtocol* delegate)
{
    // set deleate to internal player
    _internalPlayer->setDelegate(delegate);
}

ICCVideoPlayerProtocol* CCVideoPlayer::getDelegate()
{
    // return from internal player
    return _internalPlayer->getDelegate();
}