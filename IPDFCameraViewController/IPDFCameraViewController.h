//
//  IPDFCameraViewController.h
//  InstaPDF
//
//  Created by Maximilian Mackh on 06/01/15.
//  Copyright (c) 2015 mackh ag. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger,IPDFCameraViewType)
{
    IPDFCameraViewTypeBlackAndWhite,
    IPDFCameraViewTypeNormal
};

@interface IPDFCameraViewController : UIView

+ (BOOL)hasFrontCamera;
+ (BOOL)hasRearCamera;

- (void)setupCameraView;
- (void)setupCameraView:(AVCaptureDevicePosition)position orientation:(AVCaptureVideoOrientation)orientation;

- (void)start;
- (void)stop;

@property (nonatomic,assign,getter=isBorderDetectionEnabled) BOOL enableBorderDetection;
@property (nonatomic, readonly) BOOL currentDeviceHasTorch;
@property (nonatomic,assign,getter=isTorchEnabled) BOOL enableTorch;

@property (nonatomic, readonly) AVCaptureDevicePosition captureDevicePosition;

@property (nonatomic,assign) IPDFCameraViewType cameraViewType;

- (void)focusAtPoint:(CGPoint)point completionHandler:(void(^)())completionHandler;

- (void)captureAsUIImageWithCompletionHander:(void(^)(UIImage *image))completionHandler;
- (void)captureImageWithCompletionHander:(void(^)(NSString *imageFilePath))completionHandler;

@end
