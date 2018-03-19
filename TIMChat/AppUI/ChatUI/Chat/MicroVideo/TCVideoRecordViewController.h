#import <UIKit/UIKit.h>


@protocol MicroVideoRecordDelegate <NSObject>

- (void)recordVideoPath:(NSString *)path;

@end
/**
 *  短视频录制VC
 */
@interface TCVideoRecordViewController : UIViewController

@property (nonatomic, weak) id<MicroVideoRecordDelegate> delegate;

-(void)onBtnCloseClicked;

@end
