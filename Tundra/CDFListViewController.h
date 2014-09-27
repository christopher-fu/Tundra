//
//  CDFSeriesListViewController.h
//  Tundra
//
//  Created by Christopher Fu on 9/12/14.
//  Copyright (c) 2014 Christopher Fu. All rights reserved.
//

/*
 * CDFListViewController controls the logic for the series list. It contains
 * array controllers for all the status categories: currently watching,
 * compeleted, planned, on hold, and dropped. These array controllers are bound
 * to view-based NSTableView (actually CDFTableView) columns. Switching in 
 * between these categories on the NSOutlineView switches which array controller 
 * is currently bound to the table view. The list view controller is in charge
 * of handling user edits to the series list and saving those changes to the
 * Core Data store and can be perhaps considered the most important function of
 * Tundra.
 */

#import <Cocoa/Cocoa.h>
#import "CDFManagingViewController.h"
#import "CDFSeriesInfoArrayController.h"

@interface CDFListViewController : CDFManagingViewController <NSTableViewDelegate>

@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoAllArrayController;
@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoCurrentlyWatchingArrayController;
@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoCompletedArrayController;
@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoPlanToWatchArrayController;
@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoOnHoldArrayController;
@property (strong) IBOutlet CDFSeriesInfoArrayController *seriesInfoDroppedArrayController;
@property (strong) IBOutlet NSArrayController *popUpStatusNames;

@property (weak) IBOutlet NSTableView *tableView;
@property (weak) IBOutlet NSSearchField *searchField;

@property (strong) NSArray *statusNames;

- (IBAction)addSeries:(id)sender;
- (IBAction)pullData:(id)sender;

- (void)sortList;
- (void)switchBindingsToArrayController:(CDFSeriesInfoArrayController *)arrayController;
- (IBAction)dumpData:(id)sender;

@end
