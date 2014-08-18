//
//  FXPDFViewController.h
//  Foxit IOS RDK
//
//  Created by Foxit on 6/20/13.
//  Copyright (c) 2013 Foxit Corporation. All rights reserved.
//
#import "FXPDFViewControllerDelegate.h"

@interface FXPDFViewController : UIViewController<UIPopoverControllerDelegate, UIDocumentInteractionControllerDelegate, UIActionSheetDelegate, UISearchBarDelegate, FXPDFViewControllerDelegate>
/**
 * Initialize FXPDFViewController
 *
 * Example: [[FXPDFViewController alloc] init];
 */
- (id)init;

/**
 * Unlock Foxit IOS RDK with the sn and the code.
 * The sn and the code can be found in the sn.txt from Foxit IOS RDK download package.
 * This method must be called after init and prior to all the rest of API calls
 *
 * Example: [foxitViewController unlockWithSN: @"SN" andCode:@"CODE"];
 */
- (BOOL)unlockWithSN:(NSString*)sn andCode:(NSString*)code;

/**
 * Calling this API will open a PDF in the user interface.
 *
 * Example: [foxitViewController openPDF: @"/Documents/Foxit.pdf"];
 * 
 * Note: This is an asynchronous API, delegate function 'documentDidLoad' would be invoked after document is loaded.
 */
- (void)openPDF:(NSString *)pdfFilePath;
// Open the PDF from memory buffer.

/**
 *
 *
 * When a PDF file is stored as an NSData object in the memory, it can be opened through this API.
 *
 * Example: 
 * FILE* fp = fopen([path UTF8String], "rb");
 * fseek(fp, 0, SEEK_END);
 * int len = ftell(fp);
 * char* pBuff = new char[len];
 * fseek(fp, 0, SEEK_SET);
 * fread(pBuff, sizeof(char), len, fp);
 * fclose(fp);
 *
 * NSData* fileData = [NSData dataWithBytes:pBuff length:len];
 * delete[] pBuff;
 * [foxitViewController openPDFWithData:fileData];
 *
 *
 * Note: This is an asynchronous API, delegate function 'documentDidLoad' would be invoked after document is loaded.
 */
- (void)openPDFWithData:(NSData *)pdfFileData;

/**
 * It is possible to implement an FXFileReadDelegate to read file data. Thus more extensibility can be achived
 *
 * Example: [foxitViewController openPDFWithDelegate: myDelegate];
 *
 * Note: This is an asynchronous API, delegate function 'documentDidLoad' would be invoked after document is loaded.
 */
- (void)openPDFWithDelegate:(id<FXFileReadDelegate>)delegate;

/**
 * Save a PDF file to a specific place
 *
 * Example: [foxitViewController savePDF: @"/Documents/Foxit.pdf"];
 */
- (void)savePDF:(NSString *)pdfFilePath;

/**
 * Save a PDF file to a NSData structure
 *
 * If save fails, nil will be returned
 *
 * Example: NSData* pdf_data = [foxitViewController savePDFData];
 */
- (NSData*)savePDFData;

/**
 * closePDF will close the current PDF file.
 *
 * Example: [foxitViewController closePDF];
 */
- (void)closePDF;

//ViewController Configuration.

/**
 * Disable the save popup box when clicking the home button.
 *
 * Example: [foxitViewController disableSave: YES];
 */
- (void) disableSave:(BOOL)ifDisable;

/**
 * Call this function to hide or show the save popup box.If the saving function is already disabled, then the saving box is always hidden and there is no effect to call this function.
 *
 * Example: [foxitViewController hideSavingBox: YES];
 */
- (void) hideSavingBox:(BOOL)needHide;

/**
 * Whether to highlight the hyperlink in the PDF by default.
 *
 * Example: [foxitViewController setHighlightlinks: YES];
 */
- (void) setHighlightLinks:(BOOL)needHighlight;

/**
 * Set the highlight color of the links.
 *
 * Example: [foxitViewController setHighlightLinksColor: color];
 */
- (void ) setHighlightLinksColor:(UIColor*)highlightColor;

/**
 * Set the author of the annotation.
 *
 * Example: [foxitViewController setAnnotationAuthor: @"wjm"];
 */
- (void) setAnnotationAuthor:(NSString*)author;


/**
 * the combination variable can be a combination of the following values,
 * 
 *
 *
 * The PDF view's setting menu will contain:
 * "brightness", "open in", "send mail", "encryption"
 *
 * FPDFVIEWCONTROL_DEFAULT
 *
 *
 * The PDF view's setting menu will contain "brightness"
 *
 * FPDFVIEWCONTROL_OTHERFUNCS_BRIGHTNESS
 *
 *
 *
 * The PDF view's setting menu will contain "open in"
 *
 * FPDFVIEWCONTROL_OTHERFUNCS_OPEN_IN
 *
 *
 *
 * The PDF view's setting menu will contain "send mail"
 *
 * FPDFVIEWCONTROL_OTHERFUNCS_SEND_MAIL
 *
 *
 *
 * The PDF view's setting menu will contain "encryption"
 *
 * FPDFVIEWCONTROL_OTHERFUNCS_ENCRYPTION
 *
 *
 *
 * It must be called before UI gets loaded
 *
 * Example: [foxitViewController setUIPreference: FPDFVIEWCONTROL_OTHERFUNCS_BRIGHTNESS|FPDFVIEWCONTROL_OTHERFUNCS_ENCRYPTION];
 *
 */
- (void) setUIPreference:(int)combination;

/**
 * If the copyTextPermission is set to False, the "CopyText" option won't show up in the UI component.
 *
 * Example: [foxitViewController setCopyTextPermission:YES];
 */

- (void) setCopyTextPermission:(BOOL) copyTextPermission;

/**
 * Set a custom image for the back button on the navigation bar.
 *
 *
 * Example: [foxitViewController setBarBackButtonImage: [UIImage imageNamed:@"Button"]];
 */

- (void) setBarBackButtonImage:(UIImage *)barBackButtonImage;

/**
 * Set the background image for the back button on the navigation bar.
 *
 * Example: [foxitViewController setBarBackgroundImage: [UIImage imageNamed:@"Button"]];
 */

- (void) setBarBackgroundImage: (UIImage *)barBackgroundImage;

/**
 * Get or set the display mode.
 * The display mode could be,
 * Single page mode -- FPDFSinglePage
 * Continous page mode -- FPDFContinusPage
 * Thumbnail mode -- FPDFThumbnail
 *
 * Example: foxitViewController.displayMode = FPDFThumbnail;
 */

@property (nonatomic) FPDFDisplayMode  displayMode;

@end
