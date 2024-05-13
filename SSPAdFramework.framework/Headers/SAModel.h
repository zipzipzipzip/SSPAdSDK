//
//  SAModel.h
//  SSPAdFramework
//
//  Created by fc on 2021/1/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SATools.h"


typedef void (^Bindding_ECPM)(NSInteger ecpm,BOOL isExposureSucc);
//开屏
static NSString *const Notif_Splash_bidding_GDT          = @"Notif_Splash_bidding_GDT";
static NSString *const Notif_Splash_bidding_BU          = @"Notif_Splash_bidding_BU";
static NSString *const Notif_Splash_bidding_KS             = @"Notif_Splash_bidd_KS";

//插屏
static NSString *const Notif_Insert_bidding_GDT           = @"Notif_Insert_bidding_GDT";
static NSString *const Notif_Insert_bidding_BU           = @"Notif_Insert_bidding_BU";
static NSString *const Notif_Insert_bidding_KS           = @"Notif_Insert_bidding_KS";

//信息流
static NSString *const Notif_Flow_bidding_GDT           = @"Notif_Flow_bidding_GDT";
static NSString *const Notif_Flow_bidding_BU           = @"Notif_Flow_bidding_BU";
static NSString *const Notif_Flow_bidding_KS           = @"Notif_Flow_bidding_KS";

//banner
static NSString *const Notif_Banner_bidding_GDT           = @"Notif_Banner_bidding_GDT";
static NSString *const Notif_Banner_bidding_BU           = @"Notif_Banner_bidding_BU";
static NSString *const Notif_Banner_bidding_KS           = @"Notif_Banner_bidding_KS";


/*
 CGRect & CGSize
 */
CG_INLINE CGRect
CGRect_SSP(CGFloat x,CGFloat y,CGFloat width,CGFloat height){
    
    CGRect rect;
    float autoSizeScaleX;
    float autoSizeScaleY;
    
    CGFloat ScreenWidth = [[UIScreen mainScreen] bounds].size.width;
    CGFloat ScreenHeight = [[UIScreen mainScreen] bounds].size.height;
    
    if(ScreenHeight > 667){
        autoSizeScaleX = ScreenWidth/375;
        autoSizeScaleY = ScreenHeight/667;
    }else{
        autoSizeScaleX = 1.0;
        autoSizeScaleY = 1.0;
    }
    rect.origin.x = x * autoSizeScaleX;
    rect.origin.y = y * autoSizeScaleY;
    rect.size.width = width * autoSizeScaleX;
    rect.size.height = height * autoSizeScaleY;
    return rect;
}
CG_INLINE CGSize
CGSize_SSP(CGFloat width,CGFloat height){
    
    CGSize size;
    float autoSizeScaleW;
    float autoSizeScaleH;
    
    CGFloat ScreenWidth = [[UIScreen mainScreen] bounds].size.width;
    CGFloat ScreenHeight = [[UIScreen mainScreen] bounds].size.height;
    
    if(ScreenHeight > 667){
        autoSizeScaleW = ScreenWidth/375;
        autoSizeScaleH = ScreenHeight/667;
    }else{
        autoSizeScaleW = 1.0;
        autoSizeScaleH = 1.0;
    }
    size.width = width * autoSizeScaleW;
    size.height = height * autoSizeScaleH;
    return size;
}



@interface SA_material :NSObject
@property (nonatomic , copy) NSString              * crid;
@property (nonatomic , assign) NSInteger              ldptype;
@property (nonatomic , copy) NSString              * ldp;
@property (nonatomic , copy) NSString              * tempid;
@property (nonatomic , copy) NSString              * apkname;
@property (nonatomic , copy) NSString              * packagename;
@property (nonatomic , copy) NSString              * videourl;
@property (nonatomic , assign) NSInteger              duration;
@property (nonatomic , copy) NSArray<NSString *>              * imgurl;
@property (nonatomic , copy) NSString              * desc;
@property (nonatomic , copy) NSString              * adm;
@property (nonatomic , copy) NSString              * deeplink;
@property (nonatomic , copy) NSString              * miniApp;
@property (nonatomic , copy) NSString              * adsource;
@property (nonatomic , copy) NSString              * logourl;
@property (nonatomic , assign) NSInteger                isfull;

@end

@interface SA_extended :NSObject

@end

/*
 监测model
 */
@interface SA_jp :NSObject
@property (nonatomic , copy) NSString              * sdkid;
@property (nonatomic , copy) NSString              * url;
@property (nonatomic , assign) NSInteger              time;

@end

@interface SA_monitor :NSObject
@property (nonatomic , copy) NSArray<SA_jp *>              * ca;
@property (nonatomic , copy) NSString              * ldpca;
@property (nonatomic , copy) NSArray<SA_jp *>              * pa;

@end


@interface SA_sdkinfo :NSObject

@property (nonatomic , assign) NSInteger              ntagflag;
@property (nonatomic , copy) NSString              * catid;
@property (nonatomic , assign) NSInteger              sdkPrice;
@property (nonatomic , assign) NSInteger              sdkpri;
@property (nonatomic , assign) NSInteger              sdkdelay;
@property (nonatomic , assign) NSInteger              inflag;
@property (nonatomic , copy) NSString              * sdkid;
@property (nonatomic , copy) NSString              * ntagid;
@property (nonatomic , copy) NSString              * nopa;
@property (nonatomic , copy) NSString              * logo;


@end

@interface SA_data :NSObject
@property (nonatomic , copy) NSString              * crequestid;
@property (nonatomic , copy) NSString              * requestid;
@property (nonatomic , copy) NSString              * orderid;
@property (nonatomic , strong) SA_material              * material;
@property (nonatomic , assign) NSInteger              adsequence;
@property (nonatomic , strong) SA_extended              * extended;
@property (nonatomic , strong) SA_monitor              * monitor;
@property (nonatomic , copy) NSString              * sposid;
@property (nonatomic , copy) NSString              * restype;
@property (nonatomic , copy) NSArray<SA_sdkinfo *>              * sdkinfo;
//广告类型 1=开屏，2=视频贴片，3=信息流，4=banner，5=插屏，6=激励视频
@property (nonatomic , assign) NSInteger               spostype;
//广告渲染方式 0=模板渲染，1=自渲染
@property (nonatomic , assign) NSInteger               loadtype;
//0=串行，1=并行，2=竞价，3=瀑布流，4=竞价+瀑布流 默认0
@property (nonatomic , assign) NSInteger               serialflag;


@end

//数据model
@interface SAModel :NSObject
@property (nonatomic , assign) NSInteger              code;
@property (nonatomic , copy) NSArray<SA_data *>              * data;
@property (nonatomic , assign) BOOL              flag;
@property (nonatomic , copy) NSString              * message;

//原来逻辑：串并行逻辑
-(void)Series_Parallel_AdBy:(SAModel*)model sdkinfoArray:(NSMutableArray*)infoArray ADDraw:(void (^)(SA_material * material))draw BUBlock:(void (^)(SA_sdkinfo * sdkinfo))BUBlock GDTBlock:(void (^)(SA_sdkinfo * sdkinfo))GDTBlock KSBlock:(void (^)(SA_sdkinfo * sdkinfo))KSBlock;

//新逻辑：竞价+瀑布流
-(void)Bidding_AdBy:(SAModel*)model sdkinfoArray:(NSMutableArray*)infoArray ADDraw:(void (^)(SA_material * material))draw BU_bidg_block:(void (^)(SA_sdkinfo * sdkinfo))BU_bidg_block GDT_bidg_block:(void (^)(SA_sdkinfo * sdkinfo))GDT_bidg_block KS_bidg_block:(void (^)(SA_sdkinfo * sdkinfo))KS_bidg_block;


@end
