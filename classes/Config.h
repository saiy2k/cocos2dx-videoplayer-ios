//
//  Config.h
//  splatarena
//
//  Created by saiy2k on 04/04/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
//      Holds various game setting from
//          * screen configuration of the game,
//          * game settings,
//          * current game stats

#ifndef splatarena_Config_h
#define splatarena_Config_h

#include "cocos2d.h"

using namespace cocos2d;

class Config {
public:
    
    // GAMEPLAY DATA (specific to last game session)
    // *************
    
    int                             currentLevel;
    
    int								maxTexSize;

    
    
    // GAME SETTINGS
    // *************
    
    
    
    // DEVICE SPECIFIC
    // ***************
    float                           screenWidth;
    
    float                           screenHeight;
        
    float                           scaleFactor;

    static Config                   *getConfig();
};

#endif


