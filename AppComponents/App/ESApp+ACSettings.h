//
//  ESApp+ACSettings.h
//  AppComponents
//
//  Created by Elf Sundae on 16/1/22.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import <ESFramework/ESApp.h>
#import <AppComponents/ACSettings.h>

FOUNDATION_EXTERN NSString *const ACAppUserSettingsIdentifierPrefix;
FOUNDATION_EXTERN NSString *const ACAppConfigIdentifier;

@interface ESApp (ACSettings)

- (ACSettings *)userSettings;
- (ACSettings *)appConfig;

/**
 * Returns settingsIdentifier for uid: "ACAppUserSettingsIdentifierPrefix + uid"
 */
- (NSString *)userSettingsIdentifierForUserIdentifier:(NSString *)uid;

@end


@interface ESApp (ACSettingsSubclass)

- (NSString *)currentUserID;
- (NSDictionary *)userSettingsDefaults;
- (NSDictionary *)appConfigDefaults;

@end
