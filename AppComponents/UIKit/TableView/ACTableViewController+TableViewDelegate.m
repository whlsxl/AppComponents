//
//  ACTableViewController+TableViewDelegate.m
//  AppComponents
//
//  Created by Elf Sundae on 2017/01/02.
//  Copyright © 2017年 www.0x123.com. All rights reserved.
//

#import "ACTableViewController.h"

@implementation ACTableViewController (TableViewDelegate)

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *action = ESStringValue([self cellConfigForIndexPath:indexPath][ACTableViewCellConfigKeyCellAction]);
    if (action) {
        ESInvokeSelector(self, NSSelectorFromString(action), NULL, indexPath);
    }
}

- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath
{
    [self tableView:tableView didSelectRowAtIndexPath:indexPath];
}

@end
