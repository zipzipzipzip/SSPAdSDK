//
//  SATools.h
//  SSPAdFramework
//
//  Created by fc on 2020/12/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define MainW [[UIScreen mainScreen] bounds].size.width
#define MainH [[UIScreen mainScreen] bounds].size.height

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

//字符串是否为空
#define IsStringEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) isEqualToString:@""])||([(_ref) isEqualToString:@"(null)"]))
//是否为空或是[NSNull null]
#define NotNilAndNull(_ref)  (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))
/*
 广告类型
 */
typedef enum : NSUInteger {
    SAAdDrawSelf,//直投（暂无接入）
    SAAdKS,//快手
    SAAdGDT,//广点通
    SAAdBU,//穿山甲
    SAAdNone,//未知（初始化、请求等阶段无类型）
} SAAdvertiseType;
typedef enum : NSUInteger {
    SACloseNormal,//正常关闭
    SACloseSkip,//点击跳过关闭
    SACloseNone,//未知关闭
} SAAdCloseType;
/*
 渲染类型
 */
typedef enum : NSUInteger {
    SAAd_Native,//模板
    SAAd_UN_Native,//自渲染
} SAAdRenderType;
/**
 *  视频播放器状态
 *
 *  播放器只可能处于以下状态中的一种
 *
 */
typedef NS_ENUM(NSUInteger, SASSPMediaPlayerStatus) {
    SASSPMediaPlayerStatusInitial = 0,         // 初始状态
    SASSPMediaPlayerStatusLoading = 1,         // 加载中
    SASSPMediaPlayerStatusStarted = 2,         // 开始播放
    SASSPMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    SASSPMediaPlayerStatusError = 4,           // 播放出错
    SASSPMediaPlayerStatusStoped = 5,          // 播放停止
};

typedef enum : NSUInteger {
    SAJPRequst,//请求
    SAJPRenderFill,//填充
    SAJPExpoure,//曝光
    SAJPClick,//点击
    SAJPLanding,//落地页
    SAJPNone,//
} SA_JpType;


@interface SATools : NSObject

+ (instancetype)shared;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (id)copy NS_UNAVAILABLE; // 没有遵循协议可以不写
- (id)mutableCopy NS_UNAVAILABLE; // 没有遵循协议可以不写
+ (instancetype)shared;

+(NSString*)loadparams;

+(NSString*)sdk_version;

+(void)saveValue:(NSString*)value ForKey:(NSString*)key;
+(NSString*)valueWithKey:(NSString*)key;

+(void)saveDouble:(double)value ForKey:(NSString*)key;
+(double)DoubleWithKey:(NSString*)key;

+(void)saveInterger:(NSInteger)value ForKey:(NSString*)key;
+(NSInteger)IntegerWithKey:(NSString*)key;

+(void)PresentToVc:(UIViewController*)vc;

+(void)PushToVc:(UIViewController*)vc;

+(void)appStoreWithAppId:(NSString*)appId rootViewController:(UIViewController*)rootvc;

+(void)setAppid:(NSString*)appid;

+(NSString*)Appid;


+(void)SASSPConfig;

+(NSString *)macAddress;

+(NSString*)adtype:(SAAdvertiseType)type;

+(NSBundle*)bundle;
+(UIImage *)BundleImgName:(NSString*)name;

+(void)SSPLog:(BOOL)OpenLog;




@end

