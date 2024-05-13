//
//  FlowInformationAd.h
//  SSPAdFramework
//
//  Created by fc on 2021/1/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@protocol FlowInformationDelegate <NSObject>
@required

@optional

//自渲染
/**
 * 拉取广告成功的回调
 * unifiedNativeAdDataObject：广告素材信息
 *adtype：广告类型
 */
- (void)SASSPFlowAd_UN_Native_LoadDataSuccess:(NSObject *)unifiedNativeAdDataObject  type:(SAAdvertiseType)adtype;


//模板渲染
/**
 * 模板渲染拉取广告成功的回调
 */
- (void)SASSPFlowAd_LoadDataSuccess:(UIView *)view type:(SAAdvertiseType)adtype;


/**
 * 模板渲染广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)SASSPFlowAd_RenderSuccess:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 模板渲染广告渲染失败
 */
- (void)SASSPFlowAd_RenderFail:(UIView *)view type:(SAAdvertiseType)adtype;


/**
 * 拉取广告失败的回调（会多次调用）
 */
- (void)SASSPFlowAd_LoadDataError:(NSError *)error type:(SAAdvertiseType)adtype;
/*
 最终失败回调  以下两种情况会触发此回调
 1、所有广告商均返回错误后会统一调用此回调
 2、sdk如果设置了超时时长  超过后即使广告请求成功也不再展示 超时时长优先级高于其他
 */
- (void)SASSPFlowAdDidAllFail;
/**
 * 广告曝光回调
 */
- (void)SASSPFlowAd_Exposure:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 广告点击回调
 */
- (void)SASSPFlowAd_Clicked:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 广告被关闭
 */
- (void)SASSPFlowAd_Closed:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 点击广告点击以后弹出全屏广告页
 */
- (void)SASSPFlowAd_DidPresentScreen:( UIView *)view type:(SAAdvertiseType)adtype;
/**
 * 全屏广告页将要关闭
 */
- (void)SASSPFlowAd_DidDissmissScreen:(UIView *)view type:(SAAdvertiseType)adtype;

/**
 * 详解:当点击应用下载或者广告调用系统程序打开时调用
 */
//- (void)SASSPFlow_NativeExpressProAdViewApplicationWillEnterBackground:(NSArray<__kindof UIView *> *)nativeExpressProAdView;

/**
 * 视频广告 player 播放状态更新回调
 */
- (void)SASSPFlowAd_Views:( UIView *)view playerStatusChanged:(SASSPMediaPlayerStatus)status type:(SAAdvertiseType)adtype;

- (void)SASSPFlowAd_VideoDidFinished:( UIView *)view type:(SAAdvertiseType)adtype;

@end



@interface FlowInformationAd : NSObject<FlowInformationDelegate>

@property (nonatomic, weak,nullable) id<FlowInformationDelegate> delegate;

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
-(void)loadFlowInformationWithSlot:(SASlotAd *_Nullable)slot size:(CGSize)size;


// registerContainer:withClickableViews:clickableViews注册绑定点击的View并刷新数据源refreshData:。
/**
 *自渲染广告需要在物料加载成功方法里获取相关广告信息赋值后，调用此方法（模板渲染无需调用）
 *
 *  @param containerView:必需的。原生广告的容器视图。
 *  @param  ADView:视频广告的媒体View (联盟广告必传)
 *  @param clickableViews:可选。
 *  @param adtype：广告类型
 */
-(void)registerContainer:(UIView *)containerView ADView:(UIView *_Nullable)ADView
        withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews type:(SAAdvertiseType)adtype;

@end

