//
//  HHSaveLifeThread.h
//  线程保活
//
//  Created by 韩恒 on 2019/12/9.
//  Copyright © 2019 韩恒. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 
 思考:
 1: 封装此工具为什么给 NSThread 添加分类这种方式不太好?
 答:因为如果使用分类的话,给分类添加属性比较麻烦,需要用到 associate 关联对象这种技术.
 2:为什么不采用继承自 NSThread  这种方式?
 答:直接继承自 NSThread 这种方式不太安全,因为 NSThread 类中暴露了很多直接操作 线程 的 API,比如 start,cancle,stop等,
 其他使用此工具的开发者可能会调动 `NSThread` 中的方法 打乱 此工具的生命周期.这样的话我们也无法保证线程的声明
 周期,所以我们继承自 NSObject 更好一些.把线程操作相关的方法封装起来,更安全.
 
 */



@interface HHSaveLifeThread : NSObject


/**
 执行任务
 */
- (void)executeTaskWithBlock:(void(^)(void))taskBlock;

/***
 停止线程
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
