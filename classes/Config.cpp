//
//  Config.cpp
//  splatarena
//
//  Created by saiy2k on 04/04/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Config.h"

static Config *instance         =   NULL;

Config *Config::getConfig() {
    if (!instance) {
        instance                =   new Config();

        instance->currentLevel  =   3;
        glGetIntegerv(GL_MAX_TEXTURE_SIZE, &instance->maxTexSize);
    }
    return                          instance;
}
