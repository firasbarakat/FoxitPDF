//
//  FoxitPDFPluginVC.m
//  FoxitPDF
//
//  Created by Firas Barakat on 8/15/14.
//
//

#import "FoxitPDFPluginVC.h"

@interface FoxitPDFPluginVC ()

@end

@implementation FoxitPDFPluginVC
{
    NSString *_pdfPath;
    NSString *_annotationAuthor;
}

- (id)initWithPDF:(NSString*)pdfFile withAnnotationAuthor:(NSString*)annotationAuthor
{
    if(self = [super init])
    {
        _pdfPath = pdfFile;
        _annotationAuthor = annotationAuthor;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self unlockWithSN:@"SDKEDTEMP" andCode:@"5C73004A7CC3B0E37BA89FD32E5E046839E10B3A"];
    [self setAnnotationAuthor:_annotationAuthor];
    [self openPDF:_pdfPath];
}

- (void)documentWillClose
{
    NSLog(@"Document Did Close");
    [self dismissModalViewControllerAnimated:YES];
}

@end
