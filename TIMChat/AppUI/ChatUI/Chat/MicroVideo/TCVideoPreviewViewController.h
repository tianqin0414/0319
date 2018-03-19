//#import "TCLiveListModel.h"
#import <UIKit/UIKit.h>
#import <TXRTMPSDK/TXUGCRecordTypeDef.h>

#define kRecordType_Camera 0
#define kRecordType_Play 1

@protocol MicroVideoPreviewDelegate <NSObject>

- (void)previewVideoPath:(NSString *)path;
    
@end

/**
 *  短视频预览VC
 */
@interface TCVideoPreviewViewController : UIViewController
    
@property (nonatomic, weak) id<MicroVideoPreviewDelegate> delegate;
    
-(instancetype)initWith:(NSInteger)recordType  coverImage:(UIImage*)coverImage RecordResult:(TXRecordResult *)recordResult;//TCLiveInfo:(TCLiveInfo *)liveInfo;

@end
