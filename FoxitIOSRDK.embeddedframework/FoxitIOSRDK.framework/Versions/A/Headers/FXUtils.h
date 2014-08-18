//
//  FXUtils.h
//  Foxit IOS RDK
//
//  Created by Foxit on 6/20/13.
//  Copyright (c) 2013 Foxit Corporation. All rights reserved.
//
#import <UIKit/UIKit.h>

//Combine the following marcos to set UI preference.

#define FPDFVIEWCONTROL_DEFAULT                                 0x0
#define FPDFVIEWCONTROL_HIDE_TOPTOOLBAR                         0x01000000
//Not supported yet.
#define FPDFVIEWCONTROL_HIDE_OTHERFUNCS                         0x00010000

#define FPDFVIEWCONTROL_HIDE_OTHERFUNCS_BRIGHTNESS              0x00000001
#define FPDFVIEWCONTROL_HIDE_OTHERFUNCS_OPENIN                  0x00000002
#define FPDFVIEWCONTROL_HIDE_OTHERFUNCS_SENDMAIL                0x00000004
#define FPDFVIEWCONTROL_HIDE_OTHERFUNCS_ENCRYPTION              0x00000008


//Important! Do not combine the follwoing macros with above. Using these macros are not recommended.
#define FPDFVIEWCONTROL_OTHERFUNCS_BRIGHTNESS                   0x80000001
#define FPDFVIEWCONTROL_OTHERFUNCS_OPEN_IN                      0x80000002
#define FPDFVIEWCONTROL_OTHERFUNCS_SEND_MAIL                    0x80000004
#define FPDFVIEWCONTROL_OTHERFUNCS_ENCRYPTION                   0x80000008


typedef  enum{
    FPDFSinglePage = 0,
    FPDFContinusPage = 1,
    FPDFThumbnail = 2
}FPDFDisplayMode;


typedef enum {
    FXStatus_Success,
    FXStatus_Failed,
    FXStatus_Error_FileFormat,
    FXStatus_Error_FilePassword
}FXStatusCode;


@interface FXStatus : NSObject

/**
 * Get the last status of the IOS RDK.
 */
+(FXStatusCode) GetLastStatus;

@end