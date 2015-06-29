cocos2dx-videoplayer-ios
===

### Brief ###


Based on original work by [saiy2k](https://github.com/saiy2k/cocos2dx-videoplayer-ios).

This refactored, re-structured files and introduced cleaner way to hook up [MPMoviePlayerController](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerViewController_class/) to work with cocos2dx.

In the original work, it will make changes on EAGLView class which is part of cocos2dx library. But not anymore, EAGLView class is left intact. Also in coding the game, this aims to avoid using .mm file as those classes working with the game can be used to add more support on other platform i.e. Android. All in all, *you can focus on C++ purely.*

See more detail below.

### Code ###
As the core, it has the following core files.

1. **CCVideoPlayeriOS.h** and **CCVideoPlayeriOS.mm**
Low level code hooking up videoplayer stuff and cocos2d view.

2. **CCVideoPlayerWrapper.h** and **CCVideoPlayerWrapper.mm**
A bridge class interfacing low level class with C++ class (which will be only used when coding game)

3. **CCVideoPlayer.h** and **CCVideoPlayer.cpp**
Pure C++ class that will be using by users while coding game
