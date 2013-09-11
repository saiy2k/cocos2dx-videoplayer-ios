//
//  AudioManager.cpp
//  gotIsland
//
//  Created by Krithiga on 26/02/13.
//  Copyright (c) 2013 Maag Studios & Technology Pvt Ltd. All rights reserved.
//

#include <iostream>
#include "AudioManager.h"

#define kHMute                      "kHMute"

using namespace CocosDenshion;

static AudioManager                 *staticManager = NULL;

void AudioManager::playBG() {
    if(!isMute) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("backgroundMusic.mp3", true);
    }
}

void AudioManager::stopBG() {
    if(!isMute) {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
}

void AudioManager::unMute() {
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
}

void AudioManager::toggleMute() {
    isMute                      =   !isMute;
    if (isMute) {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    } else {
        playBG();
    }
    save();
}

void AudioManager::save() {
    CCUserDefault::sharedUserDefault()->setBoolForKey(kHMute, isMute);
    CCUserDefault::sharedUserDefault()->flush();
}

AudioManager* AudioManager::sharedManager() {
    if (!staticManager) {
        staticManager           =   new AudioManager();
        CCUserDefault               *uDef;
        bool                        mute;
        
        uDef                    =   CCUserDefault::sharedUserDefault();
        mute                    =   uDef->getBoolForKey(kHMute, false);
        staticManager->isMute   =   mute;
        staticManager->isMute   =   false;
    }
    return staticManager;
}
