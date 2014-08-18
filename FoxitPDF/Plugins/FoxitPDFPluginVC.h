//
//  FoxitPDFPluginVC.h
//  FoxitPDF
//
//  Created by Firas Barakat on 8/15/14.
//
//

#import <UIKit/UIKit.h>

#import <FoxitIOSRDK/FXPDFViewController.h>

@interface FoxitPDFPluginVC : FXPDFViewController <FXPDFViewControllerDelegate>

- (id)initWithPDF:(NSString*)pdfFile withAnnotationAuthor:(NSString*)annotationAuthor;

@end
