//
//  ACWebViewController.h
//  AppComponents
//
//  Created by Elf Sundae on 16/1/22.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebViewJavascriptBridge/WebViewJavascriptBridge.h>

/// 用imageBrowser打开图片.
/// URL格式：xx-image:url=xxx&rect=urlEncoded(1,2,3,4)，其中url为必须参数，rect用docElement.getBoundingClientRect()获得。
/// 或者只是一个图片地址url: xx-image:urlEncoded(imageURL)
FOUNDATION_EXTERN NSString *const ACWebViewImageBrowserScheme; // @"acwebimagescheme"

@interface ACWebViewController : UIViewController <UIWebViewDelegate>

///=============================================
/// @name Initializer
///=============================================

- (instancetype)initWithURL:(NSURL *)URL;
- (instancetype)initWithURL:(NSURL *)URL title:(NSString *)title;

///=============================================
/// @name Property
///=============================================

@property (nonatomic, strong, readonly) UIWebView *webView;
@property (nonatomic, getter=isLoading, readonly) BOOL loading;
@property (nonatomic, copy, readonly) NSURL *initializationURL; // The first loaded URL
@property (nonatomic, copy, readonly) NSString *initializationTitle;
@property (nonatomic, copy, readonly) NSString *currentPageTitle;
- (NSURL *)currentURL;
@property (nonatomic, strong, readonly) WebViewJavascriptBridge *JSBridge;

///=============================================
/// @name Configurations
///=============================================

/// Default is YES
@property (nonatomic, getter=isNetworkActivityIndicatorEnabeld) BOOL networkActivityIndicatorEnabeld;
/// Default is NO
@property (nonatomic, getter=isActivityOverlayEnabeld) BOOL activityOverlayEnabeld;
/// Default is NO
@property (nonatomic) BOOL showsErrorViewWhenFailedLoading;
/// Default is YES
@property (nonatomic) BOOL showsPageTitle;
/// Default is YES
@property (nonatomic) BOOL showsRefreshControl;
/// Default is 60.0
@property (nonatomic) NSTimeInterval requestTimeoutInterval;
/// Default is NSURLRequestUseProtocolCachePolicy
@property (nonatomic) NSURLRequestCachePolicy requestCachePolicy;
/// Default is YES：如果当前是因为网络错误导致的加载失败了的网页，网络正常后是否自动刷新
@property (nonatomic) BOOL automaticallyReloadWhenNetworkBecomesReachable;

/// Default is [ESApp sharedApp].userAgentForWebView, set to nil to use the system default user agent for UIWebView.
/// @warning It can only be set before the first loading.
@property (nonatomic, copy) NSString *requestUserAgent;
/// Default is YES, uses `SKStoreProductViewController` to open iTunes links like https//itunes.apple.com/xx/idxxxx
/// @warning It can only be set before the first loading.
@property (nonatomic, getter=isInAppStoreEnabled) BOOL inAppStoreEnabled;
/// Default is YES.
/// @warning It can only be set before the first loading.
@property (nonatomic, getter=isJSBridgeEnabled) BOOL JSBridgeEnabled;
/// Default is NO: 由WebViewController自动对网页里的图片支持查看大图，用imageController打开大图。 为NO时仅支持网页里的 xx-image: 查看大图指令。
/// @warning It can only be set before the first loading.
@property (nonatomic, getter=isImageBrowserEnabled) BOOL imageBrowserEnabled;

///=============================================
/// @name WebView Loading
///=============================================

- (void)loadURL:(NSURL *)URL;
- (void)stopLoading;
/// 刷新当前网页或加载initializedURL
- (void)reload;

@end