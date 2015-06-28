//
//  CCVideoPlayeriOS.h
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#ifndef __Farmer__CCVideoPlayeriOS__
#define __Farmer__CCVideoPlayeriOS__

#include "cocos2d.h"

class CCVideoPlayeriOS : public cocos2d::CCObject {
public:
    
    void playVideo(const char *vidPath);
    
    static CCVideoPlayeriOS *getSharedInstance();
};

#endif /* defined(__Farmer__iOSWrapper__) */
