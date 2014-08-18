//
//  FoxitPDFPlugin.m
//  FoxitPDF
//
//  Created by Firas Barakat on 8/15/14.
//
//

#import "FoxitPDFPlugin.h"

@implementation FoxitPDFPlugin {
    FoxitPDFPluginVC *pdfVC;
}

- (void)openPDF:(CDVInvokedUrlCommand *)command
{
    NSString *pdfPath = [[command.arguments objectAtIndex:0] valueForKey:@"FilePath"];
    NSString *annotationAuthor = [[command.arguments objectAtIndex:0] valueForKey:@"AnnotationAuthor"];
    
    pdfVC = [[FoxitPDFPluginVC alloc] initWithPDF:pdfPath withAnnotationAuthor:annotationAuthor];
    [self.viewController presentViewController:pdfVC animated:YES completion:nil];
}

@end
