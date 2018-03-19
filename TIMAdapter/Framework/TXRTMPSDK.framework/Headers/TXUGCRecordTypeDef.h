#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 * PlayRecord 录制类型定义
 */
typedef NS_ENUM(NSInteger, TXRecordType)
{
    RECORD_TYPE_STREAM_SOURCE                       = 1,            //视频源为正在播放的视频流
};

/*
 * CameraRecord 录制视频质量类型
 */
typedef NS_ENUM(NSInteger, TXVideoQuality)
{
    VIDEO_QUALITY_LOW                               = 0,            //resolution  360×640     fps 20   bitrate 600
    VIDEO_QUALITY_MEDIUM                            = 1,            //resolution  540×960     fps 20   bitrate 1200
    VIDEO_QUALITY_HIGH                              = 2,            //resolution  720×1280    fps 20   bitrate 2400
};

/*
 * CameraRecord 录制分辨率类型定义
 */
typedef NS_ENUM(NSInteger, TXVideoResolution)
{
    VIDEO_RESOLUTION_360_640                  = 0,
    VIDEO_RESOLUTION_540_960                  = 1,
    VIDEO_RESOLUTION_720_1280                 = 2,
};


/*
 * 录制参数定义
 */

@interface TXUGCSimpleConfig : NSObject
@property (nonatomic, assign) TXVideoQuality        videoQuality;        //录制视频质量
@property (nonatomic, retain) UIImage *             watermark;           //设置水印图片. 设为nil等同于关闭水印
@property (nonatomic, assign) CGPoint               watermarkPos;        //设置水印图片位置
@property (nonatomic, assign) BOOL                  frontCamera;         //是否是前置摄像头
@end

@interface TXUGCCustomConfig : NSObject
@property (nonatomic, assign) TXVideoResolution     videoResolution;     //自定义分辨率
@property (nonatomic, assign) int                   videoFPS;            //自定义fps   15~30
@property (nonatomic, assign) int                   videoBitratePIN;     //自定义码率   600~2400
@property (nonatomic, retain) UIImage *             watermark;           //设置水印图片. 设为nil等同于关闭水印
@property (nonatomic, assign) CGPoint               watermarkPos;        //设置水印图片位置
@property (nonatomic, assign) BOOL                  frontCamera;         //是否是前置摄像头
@end


/*
 * 录制结果错误码定义
 */
typedef NS_ENUM(NSInteger, TXRecordResultCode)
{
    RECORD_RESULT_OK                                = 0,    //录制成功（业务层主动结束录制）
    RECORD_RESULT_OK_INTERRUPT                      = 1,    //录制成功（sdk自动结束录制，可能原因：1，app进入后台，2，app被闹钟或电话打断，3，网络断连接）
    RECORD_RESULT_FAILED                            = 1001, //录制失败
};


/*
 * 录制结果
 */
@interface TXRecordResult : NSObject
@property (nonatomic, assign) TXRecordResultCode    retCode;        //错误码
@property (nonatomic, strong) NSString*             descMsg;        //错误描述信息
@property (nonatomic, strong) NSString*             videoPath;      //视频文件path
@property (nonatomic, strong) UIImage*              coverImage;     //视频封面
@end



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * 短视频发布结果错误码定义，短视频发布流程分为三步
 *    step1: 请求上传文件
 *    step2: 上传文件
 *    step3: 请求发布短视频
 */
typedef NS_ENUM(NSInteger, TXPublishResultCode)
{
    PUBLISH_RESULT_OK                               = 0,            //发布成功
    PUBLISH_RESULT_UPLOAD_REQUEST_FAILED            = 1001,         //step1: “文件上传请求”发送失败
    PUBLISH_RESULT_UPLOAD_RESPONSE_ERROR            = 1002,         //step1: “文件上传请求”收到错误响应
    PUBLISH_RESULT_UPLOAD_VIDEO_FAILED              = 1003,         //step2: “视频文件”上传失败
    PUBLISH_RESULT_UPLOAD_COVER_FAILED              = 1004,         //step2: “封面文件”上传失败
    PUBLISH_RESULT_PUBLISH_REQUEST_FAILED           = 1005,         //step3: “短视频发布请求”发送失败
    PUBLISH_RESULT_PUBLISH_RESPONSE_ERROR           = 1006,         //step3: “短视频发布请求”收到错误响应
};

/*
 * 短视频发布参数
 */
@interface TXPublishParam : NSObject
@property (nonatomic, strong) NSString*             secretId;             //secretId
@property (nonatomic, strong) NSString*             signature;            //signatuer
@property (nonatomic, strong) UIImage *             coverImage;           //封面图，如果为nil，SDK会自动截取封面图
@property (nonatomic, strong) NSString*             videoPath;            //videoPath
@end


/*
 * 短视频发布结果
 */
@interface TXPublishResult : NSObject
@property (nonatomic, assign) int                   retCode;        //错误码
@property (nonatomic, strong) NSString*             descMsg;        //错误描述信息
@property (nonatomic, strong) NSString*             videoId;        //视频文件id
@property (nonatomic, strong) NSString*             videoURL;       //视频播放地址
@property (nonatomic, strong) NSString*             coverURL;       //封面存储地址
@end
