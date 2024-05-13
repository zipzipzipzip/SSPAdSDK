//
//  SASlotAd.h
//  SSPAdFramework
//
//  Created by fc on 2021/2/3.
//

#import <Foundation/Foundation.h>
@interface SASlotAd : NSObject
/*
 渲染类型
 */
typedef enum : NSUInteger {
    Ad_Native,//模板
    Ad_UN_Native,//自渲染
    Ad_New_Native,//新模板
} SAAdType;
/*
 SSP广告位id
 */
@property(nonatomic, nullable, copy)NSString * sposid;

/*
 广告渲染方式
 */
@property(nonatomic,assign)SAAdType loadtype;

/*
 信息流模板广告背景色
 */
@property(nonatomic,strong)UIColor * _Nullable BackgroundColor;

/*
 信息流模板广告标题字体
 */
@property (nonatomic, strong) UIFont * _Nullable titleFont;

/*
 信息流模板广告标题字体颜色
 */
@property(nonatomic,strong)UIColor * _Nullable TitleColor;


/*
 sdk生成的本次请求唯一id，uuid规则  等同sasspapi中的crequestid
 */
@property(nonatomic, nullable, copy)NSString * crequestid;


@end
