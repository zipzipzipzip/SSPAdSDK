//
//  SABannerAd.h
//  SSPAdFramework
//
//  Created by fc on 2021/1/13.
//
#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SATools.h"

#import "SASlotAd.h"


@protocol SASSPBannerDelegate <NSObject>
@required

@optional

/**
 *  请求广告条数据成功后调用
 *  当接收服务器返回的广告数据成功后调用该函数
 */
- (void)SASSPBannerViewDidLoad:(UIView *_Nullable)bannerView type:(SAAdvertiseType)adtype;
/**
 *  请求广告条数据失败后调用
 *  当接收服务器返回的广告数据失败后调用该函数(会多次调用)
 */
- (void)SASSPBannerViewFailedToLoad:(UIView *_Nullable)bannerView error:(NSError *_Nullable)error type:(SAAdvertiseType)adtype;
/*
 最终失败回调  以下两种情况会触发此回调
 1、所有广告商均返回错误后会统一调用此回调
 2、sdk如果设置了超时时长  超过后即使广告请求成功也不再展示 超时时长优先级高于其他
 */
- (void)SASSPBannerAdDidAllFail;
/**
 *  banner曝光回调
 */
- (void)SASSPBannerViewWillExpose:(UIView*_Nullable)bannerView type:(SAAdvertiseType)adtype;

/**
 *  banner点击回调
 */
- (void)SASSPBannerViewClicked:(UIView *_Nullable)bannerView type:(SAAdvertiseType)adtype;

/**
 *  banner广告点击以后弹出全屏广告页完毕
 */
- (void)SASSPBannerViewDidPresentFullScreenModal:(UIView *_Nullable)bannerView type:(SAAdvertiseType)adtype;

/**
 *  全屏广告页已经被关闭
 */
- (void)SASSPBannerViewDidDismissFullScreenModal:(UIView *_Nullable)bannerView type:(SAAdvertiseType)adtype;


/**
 *  banner被用户关闭时调用
 */
- (void)SASSPBannerViewWillClose:(UIView *_Nullable)bannerView type:(SAAdvertiseType)adtype;

@end

@interface SABannerAd : NSObject<SASSPBannerDelegate>

@property (nonatomic, weak) UIViewController * _Nullable rootViewController;
@property (nonatomic, weak) id<SASSPBannerDelegate> _Nullable delegate;
/**
 超时时间
 */
@property (nonatomic, assign) CGFloat fetchDelay;
-(void)loadSSPBannerAdWithSlot:(SASlotAd*_Nullable)slot size:(CGSize)size;

@end

