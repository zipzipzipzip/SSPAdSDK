//
//  SANewBannerAd.h
//  SSPAdFramework
//
//  Created by pp on 2023/10/7.
//

#import <Foundation/Foundation.h>
@protocol SASSPNewBannerDelegate <NSObject>
@required

@optional

//模板渲染
/**
 * 模板渲染拉取广告成功的回调
 */
- (void)SASSPNewBannerAd_LoadDataSuccess:(UIView *)view type:(SAAdvertiseType)adtype;


/**
 * 模板渲染广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)SASSPNewBannerAd_RenderSuccess:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 模板渲染广告渲染失败
 */
- (void)SASSPNewBannerAd_RenderFail:(UIView *)view type:(SAAdvertiseType)adtype;


/**
 * 拉取广告失败的回调（会多次调用）
 */
- (void)SASSPNewBannerAd_LoadDataError:(NSError *)error type:(SAAdvertiseType)adtype;
/*
 最终失败回调  以下两种情况会触发此回调
 1、所有广告商均返回错误后会统一调用此回调
 2、sdk如果设置了超时时长  超过后即使广告请求成功也不再展示 超时时长优先级高于其他
 */
- (void)SASSPNewBannerAdDidAllFail;
/**
 * 广告曝光回调
 */
- (void)SASSPNewBannerAd_Exposure:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 广告点击回调
 */
- (void)SASSPNewBannerAd_Clicked:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 广告被关闭
 */
- (void)SASSPNewBannerAd_Closed:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 点击广告点击以后弹出全屏广告页
 */
- (void)SASSPNewBannerAd_DidPresentScreen:( UIView *)view type:(SAAdvertiseType)adtype;
/**
 * 全屏广告页将要关闭
 */
- (void)SASSPNewBannerAd_DidDissmissScreen:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 详解:当点击应用下载或者广告调用系统程序打开时调用
 */
//- (void)SASSPNewBanner_NativeExpressProAdViewApplicationWillEnterBackground:(NSArray<__kindof UIView *> *)nativeExpressProAdView;

/**
 * 视频广告 player 播放状态更新回调
 */
- (void)SASSPNewBannerAd_Views:( UIView *)view playerStatusChanged:(SASSPMediaPlayerStatus)status type:(SAAdvertiseType)adtype;

- (void)SASSPNewBannerAd_VideoDidFinished:( UIView *)view type:(SAAdvertiseType)adtype;

@end

@interface SANewBannerAd : NSObject<SASSPNewBannerDelegate>

@property (nonatomic, weak,nullable) id<SASSPNewBannerDelegate> delegate;

/**
 超时时间
 */
@property (nonatomic, assign) CGFloat fetchDelay;
/**
 显示信息流广告所在的控制器
 */
@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

/**
 *  @param slot  广告位 ID
 *  @param size
 */
-(void)loadSSPNewBannerAdWithSlot:(SASlotAd *_Nullable)slot size:(CGSize)size;

@end
