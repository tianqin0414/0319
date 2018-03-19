#import "TXUGCRecordTypeDef.h"


/**********************************************
 **************  短视频录制回调定义  **************
 **********************************************/
@protocol TXVideoRecordListener <NSObject>

/**
 * 短视频录制进度
 */
@optional
-(void) onRecordProgress:(NSInteger)milliSecond;

/**
 * 短视频录制完成
 */
@optional
-(void) onRecordComplete:(TXRecordResult*)result;

/**
 * 短视频录制事件通知
 */
@optional
-(void) onRecordEvent:(NSDictionary*)evt;

@end


/**********************************************
 **************  短视频发布回调定义  **************
 **********************************************/
@protocol TXVideoPublishListener <NSObject>
/**
 * 短视频发布进度
 */
@optional
-(void) onPublishProgress:(NSInteger)uploadBytes totalBytes: (NSInteger)totalBytes;

/**
 * 短视频发布完成
 */
@optional
-(void) onPublishComplete:(TXPublishResult*)result;

/**
 * 短视频发布事件通知
 */
@optional
-(void) onPublishEvent:(NSDictionary*)evt;

@end
