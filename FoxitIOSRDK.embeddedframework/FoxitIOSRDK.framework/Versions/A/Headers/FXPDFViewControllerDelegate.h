//
//  FXPDFViewControllerDelegate.h
//  Foxit IOS RDK
//
//  Created by Foxit on 6/20/13.
//  Copyright (c) 2013 Foxit Corporation. All rights reserved.
//
#import "FXUtils.h"

@protocol FXPDFViewControllerDelegate <NSObject>

@optional

/**
 * Delegate method to be called after a document is loaded.
 */

-(void) documentDidLoad;

/**
 * Delegate method to be called after a document is closed.
 */

-(void) documentDidClose;

/**
 * Delegate method to be called before a document is closed.
 */

-(void) documentWillClose;

/**
 * Delegate method to be called before a document is loaded.
 */

-(void) documentWillLoad;

/**
 * Delegate method to be called after a document is saved. If the PDF document is saved through the savePDF API, the pdfFileData will be null. Otherwise the pdfFileData will be the PDF data represented in NSMutableData type. 
 */

-(void) documentDidSave:(NSMutableData *) pdfFileData;

/**
 * Delegate method to be called before a document is saved.
 */
-(void) documentWillSave;

/**
 * Delegate method to be called when a document fails to be loaded. The msg parameter will receive the message from IOS RDK.
 */
-(void) documentFailToLoad:(NSString *)msg;

@end


@protocol FXFileReadDelegate <NSObject>

@required

/**
 *
 * Delegate method that should return what is the size of data the file reader already reads
 *
 */
- (int) GetSize;

/**
 *
 * Delegate method for reading file data. The RDK user should implement this API so that it will read the file data starting at offset parameter with the data size as the size parameter and write the data into the buffer pointer.  
 *
 */
- (int) ReadBlock:(void*)buffer dataOffset:(int)offset dataSize:(int)size;

/**
 * Delegate method for releasing related resources after reading the file. 
 */
 
- (void) Release;

@end
