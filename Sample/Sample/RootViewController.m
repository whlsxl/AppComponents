//
//  RootViewController.m
//  Sample
//
//  Created by Elf Sundae on 16/1/22.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import "RootViewController.h"
#import <IconFontKit/IFFontAwesome.h>
#import "GithubClient.h"
#import "VerifyPhoneViewController.h"

#define kCellConfigKeyAction @"action"

@implementation RootViewController

- (instancetype)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:UITableViewStyleGrouped];
    self.showsRefreshControl = YES;
    self.configuresCellWithTableData = YES;
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"AppComponents";

    dispatch_block_t helloAction = ^(){
        [self.tableView deselectRowAtIndexPath:[self.tableView indexPathForSelectedRow] animated:YES];
        [ESApp showCheckmarkHUDWithTitle:nil timeInterval:1 animated:YES];
    };

    [self.tableData addObject:
     @[@{ ACTableViewCellConfigKeyText: @"Hello",
          ACTableViewCellConfigKeyCellReuseIdentifier: @"HelloIdentifier",
          ACTableViewCellConfigKeyIconImage: [IFFontAwesome imageWithType:IFFAStar color:[UIColor es_yellowColor] fontSize:24],
          ACTableViewCellConfigKeyAccessoryType: @(UITableViewCellAccessoryDisclosureIndicator),
          ACTableViewCellConfigKeyDetailText: [[NSAttributedString alloc] initWithString:@"world" attributes:@{NSForegroundColorAttributeName: [UIColor es_oceanDarkColor]}],
          ACTableViewCellConfigKeyDetailImage: [IFFontAwesome imageWithType:IFFATwitter color:[UIColor es_twitterColor] fontSize:20],
          ACTableViewCellConfigKeyRightBadgeView: [ESBadgeView badgeViewWithText:@"New"],
          kCellConfigKeyAction: [helloAction copy] }]
    ];

    [self.tableData addObject:
     @[@{ ACTableViewCellConfigKeyText: @"WebViewController",
          ACTableViewCellConfigKeyAccessoryType: @(UITableViewCellAccessoryDisclosureIndicator),
          kCellConfigKeyAction: @"openWebViewController",
          ACTableViewCellConfigKeyIconImage: [IFFontAwesome imageWithType:IFFASafari color:[UIColor es_primaryButtonColor] fontSize:24]},
       @{ ACTableViewCellConfigKeyText: @"AuthViewController",
          ACTableViewCellConfigKeyAccessoryType: @(UITableViewCellAccessoryDisclosureIndicator),
          kCellConfigKeyAction: @"openAuthViewController",
          ACTableViewCellConfigKeyIconImage: [IFFontAwesome imageWithType:IFFAUser color:[UIColor es_facebookColor] fontSize:24]},
       @{ ACTableViewCellConfigKeyText: @"FeedbackViewController",
          ACTableViewCellConfigKeyAccessoryType: @(UITableViewCellAccessoryDisclosureIndicator),
          kCellConfigKeyAction: @"openFeedbackViewController",
          ACTableViewCellConfigKeyIconImage: [IFFontAwesome imageWithType:IFFAComments color:[UIColor es_purpleColor] fontSize:24]},
     ]];

    [self.tableData addObject:
     @[@{ ACTableViewCellConfigKeyText: @"Github API Client",
          ACTableViewCellConfigKeyAccessoryType: @(UITableViewCellAccessoryDisclosureIndicator),
          ACTableViewCellConfigKeyIconImage: [IFFontAwesome imageWithType:IFFAGithub color:nil fontSize:24],
          ACTableViewCellConfigKeyRightBadgeView: [[UIImageView alloc] initWithImage:[IFFontAwesome imageWithType:IFFAGithubAlt color:nil fontSize:24]],
          kCellConfigKeyAction: @"testGithubApiClient" },
     ]];
}

- (BOOL)refreshData
{
    if ([super refreshData]) {
        ESDispatchOnDefaultQueue(^{
            [NSThread sleepForTimeInterval:2];
            [self refreshingDataDidFinish:nil];
        });
        return YES;
    }
    return NO;
}

- (void)openWebViewController
{
    ACWebViewController *webController = [[ACWebViewController alloc] initWithURL:[NSURL URLWithString:@"https://github.com/ElfSundae/AppComponents"]];
    // webController.activityOverlayEnabeld = YES;
    webController.showsErrorViewWhenLoadingFailed = YES;
    webController.JSBridgeEnabled = YES;
    [self.navigationController pushViewController:webController animated:YES];
}

- (void)openAuthViewController
{
    VerifyPhoneViewController *authController = [[VerifyPhoneViewController alloc] init];
    [authController presentAnimated:YES];
}

- (void)openFeedbackViewController
{
    ACFeedbackViewController *feedbackController = [[ACFeedbackViewController alloc] init];
    [self.navigationController pushViewController:feedbackController animated:YES];
}

- (void)testGithubApiClient
{
    [self.tableView deselectRowAtIndexPath:self.tableView.indexPathForSelectedRow animated:YES];

    [ESApp showProgressHUDWithTitle:@"Loading..." animated:YES];
    __unused NSURLSessionDataTask *dataTask = [[GithubClient client] GET:@"repos/ElfSundae/AppComponents" parameters:@{ @"sort": @"pushed"} progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject) {
        [ESApp hideProgressHUDIfNotAutoHidden:YES];
        [[ESApp sharedApp] showImageViewControllerFromView:nil imageURL:[NSURL URLWithString:responseObject[@"owner"][@"avatar_url"]] placeholderImage:nil backgroundOptions:JTSImageViewControllerBackgroundOption_Blurred imageInfoCustomization:nil];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [ESApp hideProgressHUDIfNotAutoHidden:YES];
    }];
    // dataTask.alertFailedResponseCodeUsingTips = YES;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    id action = [self cellConfigForIndexPath:indexPath][kCellConfigKeyAction];
    if ([action isKindOfClass:[NSString class]]) {
        ESInvokeSelector(self, NSSelectorFromString(action), NULL);
    } else if (action) {
        dispatch_block_t block = action;
        block();
    }
}

- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(nonnull NSIndexPath *)indexPath
{
    [self tableView:tableView didSelectRowAtIndexPath:indexPath];
}

@end
