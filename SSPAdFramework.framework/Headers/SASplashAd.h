//
//  SASplashAd.h
//  SSPAdFramework
//
//  Created by fc on 2020/12/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SATools.h"
#import "SASlotAd.h"
//#import "SABUInterstitial.h"

/*
 本sdk为竞价sdk (穿山甲 快手 广点通)
 逻辑：1、请求ssp广告后台获取需要竞价的广告商数据id
 2、拿到广告位id分别去请求需要竞价的广告商
 3、广告商返回广告各自广告单价
 4、本地价格竞价后展示价格胜出广告
 */


@protocol SASSPSplashDelegate <NSObject>
@required

@optional

/**
 This method is called when splash ad material loaded successfully.
 开屏广告物料加载成功（竞价模式下会回调多个）
 type：区分是哪家广告商的广告
 */
-(void)SASSPSplashAdLoadSuccess:(UIView*)splashAd type:(SAAdvertiseType)adtype;

/**
 @param error : the reason of error
 开屏广告加载失败（竞价模式下会回调多个  ）
 走了此失败回调   仍展示广告属正常现象（error信息不属于正常展示的广告）
 type：区分是哪家广告商的广告
 error：错误码对应各家广告商错误码 本sdk暂未统一整合错误信息
 */
- (void)SASSPSplashAd:(UIView*)splashAd didFailWithError:(NSError * _Nullable)error type:(SAAdvertiseType)adtype;

/*
 最终失败回调  以下两种情况会触发此回调
 1、所有广告商均返回错误后会统一调用此回调
 2、sdk如果设置了超时时长  超过后即使广告请求成功也不再展示 超时时长优先级高于其他
 */
- (void)SASSPSplashAdDidAllFail;


/**
 This method is called when splash ad slot will be showing.
 开屏广告曝光 （回调一次）
 type：区分是哪家广告商的广告
 */
- (void)SASSPSplashAdWillExposured:(UIView *)splashAd type:(SAAdvertiseType)adtype;

/**
 This method is called when splash ad is clicked.
 开屏广告点击回调
 type：区分是哪家广告商的广告

 */
- (void)SASSPSplashAdDidClicked:(UIView *)splashAd type:(SAAdvertiseType)adtype;

/**
 This method is called when splash ad is about to close.
 开屏广告将要关闭回调
 type：区分是哪家广告商的广告
 */
- (void)SASSPSplashAdWillClose:(UIView *)splashAd type:(SAAdvertiseType)adtype;

/**
 This method is called when splash ad is closed.
 开屏广告已经关闭回调
 type：区分是哪家广告商的广告
 closeType：关闭类型
 */
- (void)SASSPSplashAdDidClose:(UIView *)splashAd type:(SAAdvertiseType)adtype close:(SAAdCloseType)closeType;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
//- (void)SAsplashAdDidCloseOtherController:(UIView *)splashAd interactionType:(BUInteractionType)interactionType;
//关闭新打开的页面：穿山甲的方法带有关闭的类型
//点击以后全屏广告页已经关闭
- (void)SASSPSplashAdDidCloseOtherController:(UIView *)splashAd type:(SAAdvertiseType)adtype;

/**
 This method is called when spalashAd countdown equals to zero
 开屏广告剩余时间结束回调
 暂时未用到  快手广告无读秒回调
 */
- (void)SASSPSplashAdCountdownToZero:(UIView *)splashAd type:(SAAdvertiseType)adtype;


/**
 This method is called when spalashAd skip button  is clicked.
 点击了跳过
 type：区分是哪家广告商的广告
 */
- (void)SASSPSplashAdDidClick_Skip:(UIView *)splashAd type:(SAAdvertiseType)adtype;

@end


@interface SASplashAd : NSObject<SASSPSplashDelegate>

@property(nonatomic,weak)id<SASSPSplashDelegate> _Nullable delegate;

/**
 *  @param slot  广告位 ID
 */
-(void)loadSplashWithSlot:(SASlotAd*_Nullable)slot;


/**
 开屏广告底部区域高度
 */
@property (nonatomic, assign) CGFloat bottomH;
/**
 开屏广告底部view  不传则全屏展示广告  (优先使用bottomH高度  bottomH没有获取bottomView高度  获取不到就没下面区域)
 */
@property (nonatomic, strong) UIView * _Nullable bottomView;


/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

@property (nonatomic, weak) UIWindow * _Nullable window;

@end

