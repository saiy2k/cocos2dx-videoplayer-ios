//
//  CCVideoPlayer.mm
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#import "CCVideoPlayeriOS.h"
#include "AudioManager.h"
#include "EAGLView.h"
#include "Config.h"

@implementation CCVideoPlayeriOS {
    MPMoviePlayerController *player;
}

- (id) init
{
    if (self = [super init])
    {
        NSLog(@"Init CCVideoPlayeriOS");
    }
    
    return self;
}

- (void) playVideo:(NSString *)videoPath
{
    // get the full string path
    NSString *path = [[NSBundle mainBundle] pathForResource:videoPath ofType:@"mp4"];

    // get reference to EAGLView to use in setting up below
    EAGLView *eagl = [EAGLView sharedEGLView];
    
    // create player
    NSURL *url = [NSURL fileURLWithPath:path];
    player = [[[MPMoviePlayerController alloc] initWithContentURL:url] retain];
    player.view.frame = CGRectMake(0, 0, eagl.frame.size.width, eagl.frame.size.height);
    player.fullscreen = YES;
    player.scalingMode = MPMovieScalingModeAspectFit;
    player.controlStyle = MPMovieControlStyleNone;
    // add as a subview to eagl
    [eagl addSubview:player.view];
    // play viedeo
    [player prepareToPlay];
    [player play];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(removeVideo:)
                                                 name:MPMoviePlayerPlaybackStateDidChangeNotification object:nil];
    
    //soundVolume                 =   [[MPMusicPlayerController applicationMusicPlayer] volume];
}

- (void) removeVideo:(NSNotification *) notification
{
    //NSLog(@"playback %d", player.playbackState);
    
    if (player.playbackState == MPMoviePlaybackStatePaused || player.playbackState == MPMoviePlaybackStateStopped) {
        
        NSLog(@"Remove Video");
        
        // remove player from superview
        [player.view removeFromSuperview];
        
        // release player
        [player release];
        player = nil;
        
        // remove listener
        [[NSNotificationCenter defaultCenter] removeObserver:self
                                                        name:MPMoviePlayerPlaybackStateDidChangeNotification
                                                      object:nil];
        
        // if cocos2d is paused at the moment, then resume it
        if (cocos2d::CCDirector::sharedDirector()->isPaused())
        {
            cocos2d::CCDirector::sharedDirector()->resume();
        }
        
        AudioManager::sharedManager()->playBG();
    }
}

+ (instancetype) create
{
    return [[self alloc] init];
}

@end