//
//  GLAudienceManager.h
//  GlimrSample
//
//  Created by Sven Roeder on 19/08/14.
//  Copyright (c) 2014 Glimr AB. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * GLAudienceHandler defines the callback for getting audiences
 *
 * @since v2.0.0
 */
typedef void(^GLAudienceHandler)(NSDictionary * _Nullable audiences,  NSError * _Nullable error);


/**
 * GLTagResponseFormat gives the option to retrieve the response tags in a specific format
 *
 */
typedef NS_OPTIONS(NSUInteger, GLTagResponseFormat) {
    /** The GLTagResponseFormatFlat returns the tag in a flat array
     * @since v2.0.0
     */
    GLTagResponseFormatFlat = 1,
    /** The GLTagResponseFormatMap returns the tags in a dictionary format
     * @since v2.0.0
     */
    GLTagResponseFormatMap = 2,
};


@interface GLAudienceManager : NSObject


/**
 * Init GLAudienceManager with delegate and apiToken
 *
 * @param apiToken auth token for api authorization
 *
 * @since v2.0.0
 */
- (id _Nullable)initWithApiToken:(NSUUID * _Nonnull)apiToken;


/**
 * Init GLAudienceManager with delegate and apiToken
 *
 * @param apiToken auth token for api authorization
 * @param decimals nur of decimals for geo fix resoltion sent to api
 *
 * @since v2.0.0
 */
- (id _Nonnull)initWithApiToken:(NSUUID * _Nonnull)apiToken geoFixDecimals:(int)decimals;


/**
 * Init GLAudienceManager with delegate and apiToken and custom device id
 *
 * @param apiToken auth token for api authorization
 * @param decimals nr of decimals for geo fix resoltion sent to api
 * @param trackId override tracking id with custom device id
 *
 * @since v3.0.3
 */
- (id _Nonnull)initWithApiToken:(NSUUID * _Nonnull)apiToken geoFixDecimals:(int)decimals trackId:(NSString * _Nonnull)trackId;


/**
 * Loads associated tags for a link between device and a custom audience
 *
 * @param completion the callback for the audience dictionary or error
 *
 * @since v2.0.0
 */
- (void)glimrTagsWithCompletion:(GLAudienceHandler _Nullable)completion;


/**
 * Get the latest local tags
 *
 * @return dictionary or array of tags containing list and mapped tags
 * @since v2.0.0
 */
- (id _Nullable)cachedTags:(GLTagResponseFormat)format;


/**
 * Utility method to create a query string out of a Glimr tag dict
 *
 * @param kv dictionary
 *
 * @return string
 * @since v2.0.0
 */
+ (NSString * _Nullable)toQueryString:(NSDictionary * _Nonnull)kv;

/**
 * Property to trigger requestTrackingAuthorization inside the framework
 *
 * @return string
 * @since v3.1.1
 */
@property BOOL requestTrackingAuthorization API_AVAILABLE(ios(14));;

@end
