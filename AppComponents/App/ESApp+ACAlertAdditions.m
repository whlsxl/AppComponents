//
//  ESApp+ACAlertAdditions.m
//  AppComponents
//
//  Created by Elf Sundae on 16/1/21.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import "ESApp+ACAlertAdditions.h"
#import <FontAwesomeKit/FAKFontAwesome.h>
#import <ESFramework/ESFrameworkAdditions.h>
#import <AppComponents/ACConfig.h>

@implementation ESApp (ACAlertAdditions)

- (MBProgressHUD *)progressHUD
{
        return [MBProgressHUD HUDForView:[ESApp keyWindow]];
}

- (void)hideProgressHUD:(BOOL)animated
{
        [MBProgressHUD hideAllHUDsForView:[ESApp keyWindow] animated:animated];
}

- (MBProgressHUD *)showProgressHUDWithTitle:(NSString *)title animated:(BOOL)animated
{
        [self hideProgressHUD:NO];
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[ESApp keyWindow] animated:animated];
        hud.labelText = title;
        return hud;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - CustomView

- (MBProgressHUD *)showCheckmarkHUDWithTitle:(NSString *)title timeInterval:(NSTimeInterval)timeInterval animated:(BOOL)animated
{
        MBProgressHUD *hud = self.progressHUD ?: [self showProgressHUDWithTitle:title animated:animated];
        hud.labelText = title;
        hud.detailsLabelText = nil;
        hud.mode = MBProgressHUDModeCustomView;
        static UIImage *__gCheckmarkHUDImage = nil;
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
                FAKFontAwesome *icon = [FAKFontAwesome checkIconWithSize:40.f];
                [icon addAttribute:NSForegroundColorAttributeName value:[UIColor whiteColor]];
                __gCheckmarkHUDImage = [icon imageWithSize:CGSizeMake(40.f, 40.f)];
        });
        hud.customView = [[UIImageView alloc] initWithImage:__gCheckmarkHUDImage];
        hud.minSize = CGSizeMake(64.f, 64.f);
        
        if (timeInterval <= 0.0) {
                timeInterval = ESDoubleValueWithDefault(ACConfigGet(kACConfigKey_ACApp_DefaultTipsTimeInterval), kACAppDefaultTipsTimeInterval);
        }
        [hud hide:animated afterDelay:timeInterval];
        
        return hud;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Tips

- (MBProgressHUD *)showTips:(NSString *)text detail:(NSString *)detail addToView:(UIView *)view timeInterval:(NSTimeInterval)timeInterval animated:(BOOL)animated
{
        if (!ESIsStringWithAnyText(text) && !ESIsStringWithAnyText(detail)) {
                return nil;
        }
        if (![view isKindOfClass:[UIView class]]) {
                view = [ESApp keyWindow];
        }
        if (timeInterval <= 0.0) {
                timeInterval = ESDoubleValueWithDefault(ACConfigGet(kACConfigKey_ACApp_DefaultTipsTimeInterval), kACAppDefaultTipsTimeInterval);
        }
        
        [self hideTipsOnView:view animated:NO];
        
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:animated];
        hud.labelText = text;
        hud.detailsLabelText = detail;
        hud.mode = MBProgressHUDModeText;
        hud.animationType = ESIntegerValueWithDefault(ACConfigGet(kACConfigKey_ACApp_DefaultTipsAnimationType), MBProgressHUDAnimationFade);
        [hud hide:animated afterDelay:timeInterval];
        return hud;
}

- (MBProgressHUD *)showTips:(NSString *)text addToView:(UIView *)view
{
        return [self showTips:text detail:nil addToView:view timeInterval:0 animated:YES];
}

- (MBProgressHUD *)showTips:(NSString *)text
{
        return [self showTips:text addToView:nil];
}

- (void)hideTipsOnView:(UIView *)view animated:(BOOL)animated
{
        if (![view isKindOfClass:[UIView class]]) {
                view = [ESApp keyWindow];
        }
        [MBProgressHUD hideAllHUDsForView:view animated:animated];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Common Tips

- (MBProgressHUD *)showLocalNetworkErrorTipsWithSuperview:(UIView *)superview
{
        return [self showTips:ESStringValueWithDefault(ACConfigGet(kACConfigKey_ACNetworking_LocalNetworkErrorAlertTitle), kACNetworkingLocalNetworkErrorAlertTitle) addToView:superview];
}

- (UIAlertView *)showLocalNetworkErrorAlertWithCompletion:(dispatch_block_t)completion
{
        UIAlertView *alert = [UIAlertView alertViewWithTitle:ESStringValueWithDefault(ACConfigGet(kACConfigKey_ACNetworking_LocalNetworkErrorAlertTitle), kACNetworkingLocalNetworkErrorAlertTitle)
                                                     message:nil
                                           cancelButtonTitle:@"OK"
                                             didDismissBlock:^(UIAlertView *alertView, NSInteger buttonIndex)
                              {
                                      if (completion) {
                                              completion();
                                      }
                              } otherButtonTitles:nil];
        [alert show];
        return alert;
}

@end