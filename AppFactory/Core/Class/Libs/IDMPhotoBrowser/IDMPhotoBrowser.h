//
//  IDMPhotoBrowser.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#import "IDMPhoto.h"
#import "IDMPhotoProtocol.h"
#import "IDMCaptionView.h"
#import "IDMTapDetectingImageView.h"
#import "IDMZoomingScrollView.h"

// Delgate
@class IDMPhotoBrowser;
@protocol IDMPhotoBrowserDelegate <NSObject>
@optional
- (void)willAppearPhotoBrowser:(IDMPhotoBrowser *)photoBrowser;
- (void)willDisappearPhotoBrowser:(IDMPhotoBrowser *)photoBrowser;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didShowPhotoAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didDismissAtPageIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser willDismissAtPageIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didDismissActionSheetWithButtonIndex:(NSUInteger)buttonIndex photoIndex:(NSUInteger)photoIndex;
- (IDMCaptionView *)photoBrowser:(IDMPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser imageFailed:(NSUInteger)index imageView:(IDMTapDetectingImageView *)imageView;
@end

// IDMPhotoBrowser
@interface IDMPhotoBrowser : UIViewController <UIScrollViewDelegate>

// Properties
@property (nonatomic, strong) id <IDMPhotoBrowserDelegate> delegate;

// Toolbar customization
@property (nonatomic) BOOL displayToolbar;
@property (nonatomic) BOOL displayCounterLabel;
@property (nonatomic) BOOL displayArrowButton;
@property (nonatomic) BOOL displayActionButton;
@property (nonatomic, weak) UIImage *leftArrowImage, *leftArrowSelectedImage;
@property (nonatomic, weak) UIImage *rightArrowImage, *rightArrowSelectedImage;
@property (nonatomic, weak) UIImage *actionButtonImage, *actionButtonSelectedImage;

// View customization
@property (nonatomic) BOOL displayDoneButton;
@property (nonatomic) BOOL useWhiteBackgroundColor;
@property (nonatomic, strong) UIImage *doneButtonImage;
@property (nonatomic, weak) UIColor *trackTintColor, *progressTintColor;
@property (nonatomic, assign) CGFloat doneButtonLeftInset, doneButtonTopInset;
@property (nonatomic, assign) CGSize doneButtonSize;

@property (nonatomic, weak) UIImage *scaleImage;

@property (nonatomic) BOOL arrowButtonsChangePhotosAnimated;

@property (nonatomic) BOOL forceHideStatusBar;
@property (nonatomic) BOOL usePopAnimation;
@property (nonatomic) BOOL disableVerticalSwipe;

@property (nonatomic) BOOL dismissOnTouch;

// Default value: true
// Set to false to tell the photo viewer not to hide the interface when scrolling
@property (nonatomic) BOOL autoHideInterface;

// Defines zooming of the background (default 1.0)
@property (nonatomic) float backgroundScaleFactor;

// Animation time (default .28)
@property (nonatomic) float animationDuration;

// Init
- (id)initWithPhotos:(NSArray *)photosArray;

// Init (animated from view)
- (id)initWithPhotos:(NSArray *)photosArray animatedFromView:(UIView*)view;

// Init with NSURL objects
- (id)initWithPhotoURLs:(NSArray *)photoURLsArray;

// Init with NSURL objects (animated from view)
- (id)initWithPhotoURLs:(NSArray *)photoURLsArray animatedFromView:(UIView*)view;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setInitialPageIndex:(NSUInteger)index;

// Get IDMPhoto at index
- (id<IDMPhoto>)photoAtIndex:(NSUInteger)index;


// Public original private methods

- (UIScrollView *)mainScrollView;

// Paging
- (void)tilePages;
- (BOOL)isDisplayingPageForIndex:(NSUInteger)index;
- (IDMZoomingScrollView *)pageDisplayedAtIndex:(NSUInteger)index;
- (IDMZoomingScrollView *)pageDisplayingPhoto:(id<IDMPhoto>)photo;
- (IDMZoomingScrollView *)dequeueRecycledPage;
- (void)configurePage:(IDMZoomingScrollView *)page forIndex:(NSUInteger)index;
- (void)didStartViewingPageAtIndex:(NSUInteger)index;

// Frames
- (CGRect)frameForPagingScrollView;
- (CGRect)frameForPageAtIndex:(NSUInteger)index;
- (CGSize)contentSizeForPagingScrollView;
- (CGPoint)contentOffsetForPageAtIndex:(NSUInteger)index;
- (CGRect)frameForToolbarAtOrientation:(UIInterfaceOrientation)orientation;
- (CGRect)frameForDoneButtonAtOrientation:(UIInterfaceOrientation)orientation;
- (CGRect)frameForCaptionView:(IDMCaptionView *)captionView atIndex:(NSUInteger)index;

@end
