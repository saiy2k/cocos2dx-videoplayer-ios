//
//  CCVideoPlayeriOS.h
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#ifndef __Farmer__CCVideoPlayeriOS__
#define __Farmer__CCVideoPlayeriOS__

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#include "cocos2d.h"

@interface CCVideoPlayeriOS : NSObject 

- (id) init;
- (void) playVideo:(NSString*)videoPath;
- (void) removeVideo:(NSNotification *) notification;

+ (instancetype) create;

@end

#endif /* defined(__Farmer__iOSWrapper__) */
