#import <UIKit/UIKit.h>
#import "GPUImageOpenGLESContext.h"

@interface GPUImageView : UIView <GPUImageInput>
{
}

@property (nonatomic, readonly) CGSize sizeInPixels;
@property (nonatomic, assign) BOOL needColorAdjustment;

- (void)clearVideo;
- (void)updateDisplayBuffer;

@end
