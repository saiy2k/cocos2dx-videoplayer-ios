//
//  iOSWrapper.cpp
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#include "iOSWrapper.h"
#include <MediaPlayer/MediaPlayer.h>
#include "AudioManager.h"
#include "EAGLView.h"
#include "Config.h"

static iOSWrapper *instance     =   NULL;

void iOSWrapper::playVideo(const char *vidPath) {
    
    NSString                        *string, *stringPath;
    
    stringPath                  =   [NSString stringWithUTF8String:vidPath];
    string                      =   [[NSBundle mainBundle] pathForResource:stringPath ofType:@"mp4"];
    
    [[EAGLView sharedEGLView] playTutorialVideo:string];
}

iOSWrapper *iOSWrapper::getShared() {
    if (!instance) {
        instance                =   new iOSWrapper();
    }
    return                          instance;
}