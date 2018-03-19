//
//  YoutuBeautyManager.h
//  youtubeauty
//
//  Created by peicheng on 14/12/12.
//  Copyright (c) 2014年 tencent. All rights reserved.
//


@interface YoutuBeautyManager : NSObject

+ (instancetype) sharedManager;
- (void) initMemory;    //读取数据
- (void) initMemoryWithModelPath:(NSString *)modelPath;    //读取数据, modelPath是人脸数据监测模型的绝对路径
- (void) freeMemory;    //释放内存
- (void) lockMemory;    //加锁，禁止释放内存（正在使用中）。如果调用lock之前没有init过，则自动init
- (void) unlockMemory;  //释放锁，之后可以删除内存
- (void) setMultiThreadEnabled:(BOOL)multiThreadEnable; //设置是否开启多线程人脸检测

//人脸测试数据
//- (void)initFaceMarkMemory;
//- (void)freeFaceMarkMemory;
//- (void)lockFaceMarkMemory;
//- (void)unlockFaceMarkMemory;

@end
