//
//  ViewController.m
//  线程保活
//
//  Created by 韩恒 on 2019/12/7.
//  Copyright © 2019 韩恒. All rights reserved.
//

#import "ViewController.h"
#import "HHSaveLifeThread.h"

@interface ViewController ()

@property (nonatomic,strong)HHSaveLifeThread *thread;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.thread = [[HHSaveLifeThread alloc]init];
}
//开始执行任务按钮
- (IBAction)startExecuteTask:(id)sender {
    [self.thread executeTaskWithBlock:^{
        [self threadTask];
    }];
    
    NSLog(@"123");
}

//线程执行任务的函数
- (void)threadTask{
    NSLog(@"线程真正需要执行的任务");
}

// 停止按钮的方法
- (IBAction)stopAction {
    [self.thread stop];
}


- (void)dealloc{
    NSLog(@"%s",__func__);
}

@end
