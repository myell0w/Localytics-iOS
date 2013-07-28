//
//  MTDAnalytics.h
//  MTDAnalytics
//
//  Created by Matthias Tretter on 28.07.13.
//  Copyright (c) @myell0w All rights reserved.
//


#import "LocalyticsSession.h"


NS_INLINE void MTDAnalyticsStartSession(NSString *key) {
    [[LocalyticsSession shared] startSession:key];
}

NS_INLINE void MTDAnalyticsEndSession(BOOL upload) {
    [[LocalyticsSession shared] close];

    if (upload) {
        [[LocalyticsSession shared] upload];
    }
}

NS_INLINE void MTDAnalyticsResumeSession(BOOL upload) {
    [[LocalyticsSession shared] resume];

    if (upload) {
        [[LocalyticsSession shared] upload];
    }
}

NS_INLINE void MTDAnalyticsTagScreen(NSString *screenIndentifier) {
    [[LocalyticsSession shared] tagScreen:screenIndentifier];
}

__attribute__((overloadable)) NS_INLINE void MTDAnalyticsTagEvent(NSString *event) {
    [[LocalyticsSession shared] tagEvent:event];
}

__attribute__((overloadable)) NS_INLINE void MTDAnalyticsTagEvent(NSString *event, NSDictionary *attributes) {
    [[LocalyticsSession shared] tagEvent:event attributes:attributes];
}
