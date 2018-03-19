#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <PituAlgorithm/PituAlgorithm.h>
#import <GLKit/GLKit.h>
#import "MCSampleBuffer.h"

#define kMCMovieWriterInfoDuration @"duration"

typedef enum {
    MCDataOutputFormatRGBA,
    MCDataOutputFormat420v,
    MCDataOutputFormat420f,
    MCDataOutputFormatBGRA,
    MCDataOutputFormatARGB,
} MCDataOutputFormatType;

@protocol MCDataOutputDelegate <NSObject>

-(void)MCDataOutputProcessedSampleBuffer:(MCSampleBuffer *)sampleBuffer;

@end

@interface MCDataOutput : NSObject <GPUImageInput>
{
    CVOpenGLESTextureCacheRef coreVideoTextureCache;
    CVPixelBufferRef renderTarget;
    CVOpenGLESTextureRef renderTexture;

    CGSize videoSize;
}

@property (nonatomic, weak) id<MCDataOutputDelegate> delegate;

@property (nonatomic, assign) NSTimeInterval skipVideoHeaderTime;

@property (nonatomic, assign) MCDataOutputFormatType format;

@property (nonatomic, assign) CMSampleBufferRef referenceBuffer;

// 默认为NO，启用此属性可以减少一些copy耗时加快速度，但是有比较大的风险
@property (nonatomic, assign) BOOL ignoreIOSurfaceBack;

@property (nonatomic, assign) BOOL enableCostLog;

// Initialization and teardown
- (id)initWithVideoSize:(CGSize)newSize;
- (id)initWithVideoSize:(CGSize)newSize format:(MCDataOutputFormatType)format;

- (void)finishOutputing:(void (^)(NSDictionary *info))handler;

@end
