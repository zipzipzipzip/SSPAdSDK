//
//  SAInterstitialAd.h
//  SSPAdFramework
//
//  Created by jy on 2021/1/16.
//

#import <Foundation/Foundation.h>

#import "SAInterstitialAd.h"
#import "SATools.h"

#import <UIKit/UIKit.h>


@protocol SASSP_InterstitialDelegate <NSObject>
@required

@optional

/**
 *  插屏广告预加载成功回调
 *  当接收服务器返回的广告数据成功后调用该函数
 */
- (void)SASSP_InterAdLoadSuccess:(SAAdvertiseType)adtype;

/**
 *  插屏广告预加载失败回调
 *  当接收服务器返回的广告数据失败后调用该函数
 */
- (void)SASSP_InterLoadAdError:(NSError * _Nullable)error type:(SAAdvertiseType)adtype;
/**
 *渲染成功
 */
- (void)SASSP_InterRenderSuccess:(SAAdvertiseType)adtype;

/**
 *渲染失败
 */
- (void)SASSP_InterRenderFail:(NSError* _Nullable)error type:(SAAdvertiseType)adtype;
/**
 *即将展示
 */
- (void)SASSP_InterWillVisible:(SAAdvertiseType)adtype;

/**
 *  插屏广告点击回调
 */
- (void)SASSP_InterClicked:(SAAdvertiseType)adtype;


/**
 *  全屏广告页被关闭
 */
- (void)SASSP_InterDidDismissFullScreen:(SAAdvertiseType)adtype;


/**
 * 插屏关闭
 */
- (void)SASSP_InterWillClose:(SAAdvertiseType)adtype;


/**
 *  插屏广告曝光回调
 */
- (void)SASSP_InterWillExposure:(SAAdvertiseType)adtype;


/*
 最终失败回调  以下两种情况会触发此回调
 1、所有广告商均返回错误后会统一调用此回调
 2、sdk如果设置了超时时长  超过后即使广告请求成功也不再展示 超时时长优先级高于其他
 */
- (void)SASSP_InterstitialAdDidAllFail;

@end

@interface SAInterstitialAd : NSObject<SASSP_InterstitialDelegate>

@property (nonatomic, weak) id<SASSP_InterstitialDelegate> _Nullable delegate;
@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

/**
 *  拉取广告超时时间，默认为5秒

 */
@property (nonatomic, assign) CGFloat fetchDelay;
//广告类型
@property (nonatomic, assign,readonly) SAAdvertiseType adType;

- (void)loadInterstitialSlot:(SASlotAd*_Nullable)slot;

@end

