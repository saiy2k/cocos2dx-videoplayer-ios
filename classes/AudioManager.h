//
//  AudioManager.h
//  gotIsland
//
//  Created by Krithiga on 26/02/13.
//  Copyright (c) 2013 Maag Studios & Technology Pvt Ltd. All rights reserved.
//

#ifndef gotIsland_AudioManager_h
#define gotIsland_AudioManager_h

#include<cocos2d.h>
#include "SimpleAudioEngine.h"

using namespace cocos2d;

class AudioManager : public CCObject {
public:
    
    bool                            isMute;
    
    void                            playBG();
    void                            stopBG();
    
    void                            unMute();
    void                            toggleMute();
    void                            save();
    
    static AudioManager*            sharedManager();
    
};

#endif
