//
//  WrapperClass.h
//  Farmer
//
//  Created by saiy2k on 07/09/13.
//
//

#ifndef __Farmer__WrapperClass__
#define __Farmer__WrapperClass__

#include "cocos2d.h"

using namespace cocos2d;

class WrapperClass : public cocos2d::CCObject {
public:
    
    void                            playVideo(const char *vidPath);
    
    static WrapperClass             *getShared();
};

#endif /* defined(__Farmer__WrapperClass__) */
