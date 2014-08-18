//
//  FoxitPDFPlugin.h
//  FoxitPDF
//
//  Created by Firas Barakat on 8/15/14.
//
//

#import <Cordova/CDVPlugin.h>

#import "FoxitPDFPluginVC.h"

@interface FoxitPDFPlugin : CDVPlugin

- (void)openPDF:(CDVInvokedUrlCommand*)command;

@end
