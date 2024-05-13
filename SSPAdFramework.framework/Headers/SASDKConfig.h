//
//  SASDKConfig.h
//  SSPAdFramework
//
//  Created by fc on 2021/1/13.
//

#import <Foundation/Foundation.h>
//#import <SSPAdFramework/SAModel.h>

@interface SASDKConfig : NSObject

+(instancetype)shared;
/**
 * 获取 SDK 版本
 */

+ (NSString *)sdkVersion;

/*
 第三方广告网站注册的appid
 appid可为空：即视为不请求此家的广告
 
 区分正式和测试
 正式和测试需在对应官网上注册并取对应平台id
 
 SSPAppid : ssp的appid
 GDTAppid : 广点通的appid
 BUAppid  : 穿山甲的appid
 */
-(void)registerSSPAppid:(NSString*)SSPAppid GDTAppid:(NSString*)GDTAppid BUAppid:(NSString*)BUAppid KSAppid:(NSString *)KSAppid;
/**
 * 是否需要打印日志
 */
-(void)Openlog:(BOOL)OpenLog;

// 个性化推荐开关：关闭后，看到的⼴告数量不变，相关度将降低。
// 是否允许开启⼴告的个性化推荐（NO-关闭，YES-开启），由开发者通过SDK的接⼝来设置。不设置的话则默认为YES。
- (void)setEnablePersonalRecommend:(BOOL)enable;
// 程序化推荐开关：关闭后，看到的⼴告数量不变，但将不会为你推荐程序化⼴告。
// 是否允许开启⼴告的程序化推荐（NO-关闭，YES-开启），由开发者通过SDK的接⼝来设置。不设置的话则默认为YES。
- (void)setEnableProgrammaticRecommend:(BOOL)enable;

@end
