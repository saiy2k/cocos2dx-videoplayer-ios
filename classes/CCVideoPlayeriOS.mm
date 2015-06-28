//
//  CCVideoPlayer.mm
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#include "CCVideoPlayeriOS.h"
#include <MediaPlayer/MediaPlayer.h>
#include "AudioManager.h"
#include "EAGLView.h"
#include "Config.h"

void CCVideoPlayeriOS::playVideo(const char *vidPath) {
    
    NSString *string, *stringPath;
    
    stringPath = [NSString stringWithUTF8String:vidPath];
    string = [[NSBundle mainBundle] pathForResource:stringPath ofType:@"mp4"];
    
    [[EAGLView sharedEGLView] playTutorialVideo:string];
}

CCVideoPlayeriOS *CCVideoPlayeriOS::getSharedInstance() {
    static dispatch_once_t once;
    static CCVideoPlayeriOS *sharedInstance;
    dispatch_once(&once, ^{
        sharedInstance = new CCVideoPlayeriOS();
    });
    return sharedInstance;
}