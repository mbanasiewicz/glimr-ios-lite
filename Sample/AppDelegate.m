//
//  AppDelegate.m
//  Sample
//
//  Copyright (c) 2018 Glimr AB. All rights reserved.
//

#import "AppDelegate.h"
#import <CoreLocation/CoreLocation.h>
#import <GLGeoRealtime/GLGeoRealtime.h>

@implementation AppDelegate {
    CLLocationManager *_dummyLocationManager;
}

#define GLIMR_API_TOKEN @"B3945743-D258-49D0-AFBF-1E409AE59501"

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // THIS IS JUST TO MAKE SURE WE GET LOCATION PERMISSION FOR THE APP
    _dummyLocationManager = [[CLLocationManager alloc] init];
    [_dummyLocationManager requestWhenInUseAuthorization];
    
    // RECEIVE GLIMR TAGS
    NSUUID *apiToken = [[NSUUID alloc] initWithUUIDString:GLIMR_API_TOKEN];

    GLAudienceManager *audienceManager = [[GLAudienceManager alloc] initWithApiToken:apiToken geoFixDecimals:4];
    NSLog(@"Cached tags %@", [audienceManager cachedTags:GLTagResponseFormatFlat]);
    
    [audienceManager glimrTagsWithCompletion:^(NSDictionary *audiences, NSError *error) {
        NSLog(@"Tags %@", audiences);
    }];
}

@end
