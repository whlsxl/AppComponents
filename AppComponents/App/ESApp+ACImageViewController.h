//
//  ESApp+ACImageViewController.h
//  AppComponents
//
//  Created by Elf Sundae on 16/1/25.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import <ESFramework/ESApp.h>
#import <ElfSundae-JTSImageViewController/JTSImageViewController.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - JTSImageInfo (ACAdditions)

@interface JTSImageInfo (ACAdditions)

/// Default is YES.
@property (nonatomic) BOOL canSaveToPhotoLibrary;
/// Default is NO.
@property (nonatomic) BOOL canCopy;

@end

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - ESApp (ACImageViewController)

@interface ESApp (ACImageViewController)
<JTSImageViewControllerDismissalDelegate, JTSImageViewControllerInteractionsDelegate>

@property (nonatomic, strong) JTSImageViewController *imageViewControler;
@property (nonatomic) JTSImageViewControllerBackgroundOptions imageViewControllerDefaultBackgroundOptions;

- (JTSImageViewController *)showImageViewControllerWithImageInfo:(JTSImageInfo *)imageInfo
                                               backgroundOptions:(JTSImageViewControllerBackgroundOptions)backgroundOptions;

/// with [self imageViewControllerDefaultBackgroundOptions]
- (JTSImageViewController *)showImageViewControllerWithImageInfo:(JTSImageInfo *)imageInfo;

- (JTSImageViewController *)showImageViewControllerFromView:(UIView *)view
                                                      image:(UIImage *)image
                                          backgroundOptions:(JTSImageViewControllerBackgroundOptions)backgroundOptions
                                     imageInfoCustomization:(void (^)(JTSImageInfo *imageInfo))imageInfoCustomization;

- (JTSImageViewController *)showImageViewControllerFromView:(UIView *)view
                                                      image:(UIImage *)image;

- (JTSImageViewController *)showImageViewControllerFromView:(UIView *)view
                                                   imageURL:(NSURL *)imageURL
                                           placeholderImage:(UIImage *)placeholderImage
                                          backgroundOptions:(JTSImageViewControllerBackgroundOptions)backgroundOptions
                                     imageInfoCustomization:(void (^)(JTSImageInfo *imageInfo))imageInfoCustomization;

- (JTSImageViewController *)showImageViewControllerFromView:(UIView *)view
                                                   imageURL:(NSURL *)imageURL
                                           placeholderImage:(UIImage *)placeholderImage;

- (JTSImageViewController *)showImageViewController:(id)imageOrURL;

- (void)dismissImageViewController:(BOOL)animated completion:(dispatch_block_t)completion;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - JTSImageViewController Delegate Methods

// 这里列出了ESApp实现了的delegate方法，如果你在调用了 -showImageViewController... 方法后设置了相关delegate，可以在你的实现中调用这里的实现。

/**
 * 清理 self.imageViewController
 */
- (void)imageViewerDidDismiss:(JTSImageViewController *)imageViewer;

/**
 * 根据imageInfo里的 -canCopy 等属性判断是否弹窗ActionSheet
 */
- (void)imageViewerDidLongPress:(JTSImageViewController *)imageViewer atRect:(CGRect)rect;

@end
