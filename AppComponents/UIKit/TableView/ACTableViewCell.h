//
//  ACTableViewCell.h
//  AppComponents
//
//  Created by Elf Sundae on 16/1/29.
//  Copyright © 2016年 www.0x123.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/// NSNumber with UITableViewCellAccessoryType
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyAccessoryType;
/// NSNumber with UITableViewCellSelectionStyle
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeySelectionStyle;
/// NSString/NSAttributedString
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyText;
/// NSString/NSAttributedString
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailText;
/// UIView instance
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyLeftBadgeView;
/// UIView instance
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyRightBadgeView;
/// UIImage/NSURL/NSString
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImage;
/// UIImage
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImagePlaceholder;
/// NSNumber with BOOL
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyAlwaysShowsIconImageView;
/// NSValue with CGSize
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImageViewSize;
/// NSValue with UIEdgeInsets
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImageViewInset;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImageViewCornerRadius;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImageViewBorderWidth;
/// UIColor
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyIconImageViewBorderColor;
/// UIImage/NSURL/NSString
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImage;
/// UIImage
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImagePlaceholder;
/// NSNumber with BOOL
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyAlwaysShowsDetailImageView;
/// NSValue with CGSize
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewSize;
/// NSValue with UIEdgeInsets
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewInset;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewCornerRadius;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewBorderWidth;
/// UIColor
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewBorderColor;
/// NSNumber with BOOL
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyDetailImageViewMostRight;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyCellPadding;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyCellMarginLeft;
/// NSNumber with CGFloat
FOUNDATION_EXTERN NSString *const ACTableViewCellConfigKeyCellMarginRight;

/*!
 * Cell struct:
 *
 * @code
 * [iconImageView] textLabel [leftBadgeView] [rightBadgeView] [detailImageView] [detailTextLabel]
 * @endcode
 */
@interface ACTableViewCell : UITableViewCell
{
    UIImageView *_iconImageView;
    UIImageView *_detailImageView;
    UIView *_leftBadgeView;
    UIView *_rightBadgeView;
}

@property (nonatomic, readonly) UITableViewCellStyle cellStyle;

/// a dictionary of cell configurations.
@property (nonatomic, strong) NSDictionary *configDictionary;

/// default is nil. iconImageView will be created if necessary.
@property (nonatomic, strong, readonly) UIImageView *iconImageView;
/// default is nil. detailImageView will be created if necessary.
@property (nonatomic, strong, readonly) UIImageView *detailImageView;

/// if leftBadgeView is not nil, it will be right aligned to iconImageView or textLabel
@property (nonatomic, strong) UIView *leftBadgeView;
/// if rightBadgeView is not nil, it will be left aligned to detailImageView or detailTextLabel
@property (nonatomic, strong) UIView *rightBadgeView;

/// default is NO
@property (nonatomic) BOOL alwaysShowsIconImageView;
/// 如果不设置，则size是由iconImageViewInset约束在contentView里的正方形
@property (nonatomic) CGSize iconImageViewSize;
/// default is +[ACTableViewCell defaultIconImageEdgeInsets]
@property (nonatomic) UIEdgeInsets iconImageViewInset;
/// default is 0. when it is not zero, the iconImageView's layer's mask will be set
@property (nonatomic) CGFloat iconImageViewCornerRadius;
/// default is 0, 注意：borderWidth是通过layer.borderWidth设置的，在大数据的tableView中会影响滑动效率
@property (nonatomic) CGFloat iconImageViewBorderWidth;
/// default is +[ACTableViewCell defaultBorderColor]
@property (nonatomic, strong) UIColor *iconImageViewBorderColor;

/// default is NO
@property (nonatomic) BOOL alwaysShowsDetailImageView;
/// 如果不设置的话自动根据detailImageViewEdgeInsets计算，正方形
@property (nonatomic) CGSize detailImageViewSize;
/// default is +[ACTableViewCell defaultDetailImageEdgeInsets]
@property (nonatomic) UIEdgeInsets detailImageViewInset;
/// default is 0. when it is not zero, the iconImageView's layer's mask will be set
@property (nonatomic) CGFloat detailImageViewCornerRadius;
/// default is 0, 注意：borderWidth是通过layer.borderWidth设置的，在大数据的tableView中会影响滑动效率
@property (nonatomic) CGFloat detailImageViewBorderWidth;
/// default is +[ACTableViewCell defaultBorderColor]
@property (nonatomic, strong) UIColor *detailImageViewBorderColor;
/// Determines the detailImageView is on the mostright of contentView, defaults to NO.
@property (nonatomic, getter = isDetailImageViewMostRight) BOOL detailImageViewMostRight;

/// default is 5.f, contentView中各个view的padding
@property (nonatomic) CGFloat cellPadding;
/// defualt is 10.f
@property (nonatomic) CGFloat cellMarginLeft;
/// defualt is 10.f
@property (nonatomic) CGFloat cellMarginRight;

/**
 * Applies defaults value for properties
 */
- (void)applyDefaults;

/**
 * Config cell with dictionary.
 */
- (void)configureWithDictionary:(NSDictionary *)configDictionary;

/// [UIColor es_lightBorderColor]
+ (UIColor *)defaultBorderColor;
/// (8.f, 10.f, 8.f, 10.f)
+ (UIEdgeInsets)defaultIconImageViewInset;
/// (8.f, 5.f, 8.f, 5.f)
+ (UIEdgeInsets)defaultDetailImageViewInset;
/// 4.f
+ (CGFloat)defaultCellPadding;
/// 10.f
+ (CGFloat)defaultCellMarginLeft;
/// 10.f
+ (CGFloat)defaultCellMarginRight;

@end

/// ACTableViewCell with UITableViewCellStyleValue1 style.
@interface ACTableViewDetailCell : ACTableViewCell
@end

/// ACTableViewCell with UITableViewCellStyleValue2 style.
@interface ACTableViewCenterLabelCell : ACTableViewCell
@end

/// ACTableViewCell with UITableViewCellStyleSubtitle style.
@interface ACTableViewSubtitleCell : ACTableViewCell
@end
