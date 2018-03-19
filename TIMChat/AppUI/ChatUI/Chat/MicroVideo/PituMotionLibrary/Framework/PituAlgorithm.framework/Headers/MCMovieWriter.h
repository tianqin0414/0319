#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <PituAlgorithm/PituAlgorithm.h>
#import <GLKit/GLKit.h>


#define kMCMovieWriterInfoDuration @"duration"

@protocol MCMovieWriterDelegate <NSObject>

@optional
-(void)MovieWriterDidStartRecording:(id)sender;
-(void)MovieWriterDidAppendFrameBuffer:(id)sender withInfo:(NSDictionary *)info;
-(void)Completed;
-(void)Failed:(NSError*)error;

@end

@interface MCMovieWriter : NSObject <GPUImageInput>
{
    CMVideoDimensions videoDimensions;
	CMVideoCodecType videoType;

    NSURL *movieURL;
	AVAssetWriter *assetWriter;
    BOOL assetWriterStarted;
	AVAssetWriterInput *assetWriterAudioInput;
	AVAssetWriterInput *assetWriterVideoInput;
    AVAssetWriterInputPixelBufferAdaptor *assetWriterPixelBufferInput;
	dispatch_queue_t movieWritingQueue;
    
    CVOpenGLESTextureCacheRef coreVideoTextureCache;
    CVPixelBufferRef renderTarget;
    CVOpenGLESTextureRef renderTexture;

    CGSize videoSize;
}
@property (nonatomic, readonly) AVAssetWriter *assetWriter;

@property (readwrite, nonatomic) BOOL hasAudioTrack;
@property (readwrite, nonatomic) BOOL shouldPassthroughAudio;
@property (nonatomic, copy) void(^CompletionBlock)(void);
@property (nonatomic, copy) void(^FailureBlock)(NSError*);
@property (nonatomic, assign) id<MCMovieWriterDelegate> delegate;
@property (readwrite, nonatomic) BOOL encodingLiveVideo;
@property (nonatomic, copy) void(^videoInputReadyCallback)(void);
@property (nonatomic, copy) void(^audioInputReadyCallback)(void);
@property (nonatomic, assign) NSTimeInterval skipVideoHeaderTime;

@property (nonatomic, strong) GLKTextureInfo *watermark;

// Initialization and teardown
- (id)initWithMovieURL:(NSURL *)newMovieURL size:(CGSize)newSize;
- (id)initWithMovieURL:(NSURL *)newMovieURL size:(CGSize)newSize bitRate:(int)bitRate;
- (id)initWithMovieURL:(NSURL *)newMovieURL size:(CGSize)newSize liveVideo:(BOOL)liveVideo;
- (id)initWithMovieURL:(NSURL *)newMovieURL size:(CGSize)newSize bitRate:(int)bitRate liveVideo:(BOOL)liveVideo;

// Movie recording
//- (void)startRecording; // 这个方法实际不需要调用，传入第一帧数据后会自动启动
- (void)finishRecording:(void (^)(NSDictionary *info))handler;
- (void)processAudioBuffer:(CMSampleBufferRef)audioBuffer;
- (void)enableSynchronizationCallbacks;
- (void)setHasAudioTrack:(BOOL)newValue;

@end
