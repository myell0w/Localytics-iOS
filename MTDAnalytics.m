//
//  MTDAnalytics.m
//  Reddiscuss
//
//  Created by Matthias Tretter on 28.07.13.
//  Copyright (c) 2013 Vienna University of Technology. All rights reserved.
//


static BOOL mtd_supportsPremiumFeatures = NO;


void MTDAnalyticsSetIsPremiumAccount(BOOL premiumAccount) {
    mtd_supportsPremiumFeatures = premiumAccount;
}

void MTDAnalyticsTagScreen(NSString *screenIndentifier) {
    [[LocalyticsSession shared] tagScreen:screenIndentifier];

    // tagging screens is only available with a premium account, this is a simple workaround
    if (!mtd_supportsPremiumFeatures) {
        MTDAnalyticsTagEvent([@"Screen_" stringByAppendingString:screenIndentifier]);
    }
}
