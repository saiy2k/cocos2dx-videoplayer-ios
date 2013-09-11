//
//  iOSWrapper.h
//  Farmer
//
//  Created by Lekshmi on 28/08/13.
//
//

#ifndef __Farmer__iOSWrapper__
#define __Farmer__iOSWrapper__

#include "cocos2d.h"

class iOSWrapper : public cocos2d::CCObject {
public:
    
    void                            playVideo(const char *vidPath);
    
    static iOSWrapper               *getShared();
};

#endif /* defined(__Farmer__iOSWrapper__) */
