/*****************************************************//**
    \file         glk.h
    \author       Laurent GROSBOIS <laurent.grosbois@chromlech.fr>
    \copyright      Chromlech - 2014. All right reserved.
                     This file is provided freely and can be redistributed and editted.

    \date         14 avr. 2014
    \brief        Definitions for Matrix Orbital LCD : GLK19264-7T-1U

 \par
 The author is supplying this file with the intend it can be useful to anybody
 needing a library working with matrix orbital LCD.
 If it happens you make significant file for this file, extend the library, or

 \par
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
               
*********************************************************/


#ifndef GLK_H_
#define GLK_H_

/********************************************************
        Includes
*********************************************************/

//#include "types.h"


/********************************************************
        Definitions
*********************************************************/

/**
 * I2C Default address
 * 0x28 According to I2C Standard address
 *
 * NB : Matrix Orbital Datasheet address considers 8-bit addresses - taking I2C write/read byte into account.
 * A 0x28 7bits standard I2C address will be described as a (0x28<<1) = 0x50 Address
 */
#define GLK_I2C_ADDR            0x28

/**
 * Escape char for CMD
 */
#define    GLK_CMD_BYTE            0xFE


// ---        Communication commands        ---

#define GLK_COM_BR                            0x39        //Change Baud rate
    #define    GLK_COM_BR_9600                        207            // 9600 kbps
    #define    GLK_COM_BR_14400                    138            // 14400 kbps
    #define    GLK_COM_BR_19200                    103            // 19200 kbps
    #define    GLK_COM_BR_28800                    68            // 28800 kbps
    #define    GLK_COM_BR_38400                    51            // 38400 kbps
    #define    GLK_COM_BR_57600                    34            // 57600 kbps
    #define    GLK_COM_BR_76800                    25            // 76800 kbps
    #define    GLK_COM_BR_115200                    16            // 115200 kbps
#define GLK_COM_I2C_ADDR                    0x33        // Set I2C address
#define    GLK_COM_PROTO                        0xA0        // Transmission protocol select
    #define GLK_COM_PROTO_I2C                    0            // I2C protocol selection
    #define GLK_COM_PROTO_SERIAL                1            // RS232/RS432/USb selection
#define GLK_COM_FLOWC                        0x3F        // Flow Control mode
    #define    GLK_COM_FLOWC_NONE                    0            // No flow control
    #define    GLK_COM_FLOWC_SW                    1            // Software flow control
    #define    GLK_COM_FLOWC_HW                    2            // Hardware flow control
#define GLK_COM_FLOWC_HWTRIG                0x3E        // Hardware flow control trigger level
    #define GLK_COM_FLOWC_HWTRIG_1byte            0            // 1 byte - level 0
    #define GLK_COM_FLOWC_HWTRIG_4bytes            1            // 4 bytes - level 1
    #define GLK_COM_FLOWC_HWTRIG_8bytes            2            // 8 bytes - level 2
    #define GLK_COM_FLOWC_HWTRIG_14bytes        3            // 14 bytes - level 3
#define GLK_COM_FLOWC_SW_ON                    0x3A        // Software flow control on
#define GLK_COM_FLOWC_SW_OFF                0x3B        // Software flow control off
#define GLK_COM_FLOWC_RESP                    0x3C        // Software flow control response
#define GLK_COM_ECHO                        0xFF        // Echo
#define    GLK_COM_DELAY                        0xFB        // Delay
#define    GLK_COM_RST0                        0xFD        // RST byte 0
#define    GLK_COM_RST1                        0x4D        // RST byte 1
#define    GLK_COM_RST2                        0x4F        // RST byte 2
#define    GLK_COM_RST3                        0x75        // RST byte 3
#define    GLK_COM_RST4                        0x6E        // RST byte 4


// ---        Text commands        ---

#define GLK_TXT_CLS                            0x58        // Clear screen
#define GLK_TXT_GO_HOME                        0x48        // Set cursor to top left of screen
#define GLK_TXT_CURS_POS                    0x47        // Set cursor position
#define GLK_TXT_CURS_COORD                    0x79        // Set cursor coordinates
#define GLK_TXT_WINIT                        0x2B        // Init text window
#define GLK_TXT_WSELECT                        0x2A        // Select text window
#define GLK_TXT_WCLS                        0x2C        // Clear txt window
#define GLK_TXT_LINIT                        0x2D        // Init Label
#define GLK_TXT_LUPDATE                        0x2E        // Update label with new text
#define GLK_TXT_AUTO_SCROLL_ON                0x51        // Auto scroll on
#define GLK_TXT_AUTO_SCROLL_OFF                0x52        // Auto scroll off


// ---        Drawing  commands        ---

#define GLK_DRAW_COLOR                        0x63        // Select drawing color
#define GLK_DRAW_PIX                        0x70        // Draw single pixel
#define GLK_DRAW_LINE                        0x6C        // Draw line
#define GLK_DRAW_LINE_CONT                    0x65        // Draw continue line
#define GLK_DRAW_RECT                        0x72        // Draw rectangle
#define GLK_DRAW_FRECT                        0x78        // Draw filled rectangle
#define GLK_DRAW_RRECT                        0x80        // Draw Rounded rectangle
#define GLK_DRAW_FRRECT                        0x81        // Draw filled rounded rectangle
#define GLK_DRAW_CIRCLE                        0x7B        // Draw circle
#define GLK_DRAW_FCIRCLE                    0x7C        // Draw filled circle
#define GLK_DRAW_ELLIPSE                    0x7D        // Draw Ellipse
#define GLK_DRAW_FELLIPSE                    0x7F        // Draw filled ellipse
#define GLK_DRAW_SCROLL_SCREEN                0x59        // Scroll screen
#define GLK_DRAW_BGRAPH_INIT                0x67        // Init bar graph
#define GLK_DRAW_9SLICE_BGRAPH_INIT            0x73        // Init 9-slice bar graph
#define GLK_DRAW_BGRAPH                        0x69        // Draw bar graph
#define GLK_DRAW_STRIPCHART_INIT            0x6E        // Strip Chart init
#define GLK_DRAW_STRIPCHART_UPDATE            0x6F        // Strip Chart update
#define GLK_DRAW_UPLOAD_FONT                0x24        // Upload a font file
#define GLK_DRAW_SET_FONT                    0x31        // Set current font
#define GLK_DRAW_SET_FONT_METRICS            0x32        // Set font metrics
#define GLK_DRAW_BOXSPACE                    0xAC        // Set toggle box space mode

// todo : font file struct


// ---        Bitmaps  commands        ---

#define GLK_BITMAP_UPLOAD_FILE                0x5E        // Upload bitmap file
#define GLK_BITMAP_UPLOAD_MASK0                0x5C        // Upload bitmap mask (byte 0)
#define GLK_BITMAP_UPLOAD_MASK1                0x05        // Upload bitmap mask (byte 1)
#define GLK_BITMAP_DRAW_FROM_MEM            0x62        // Draw bitmap from memory
#define GLK_BITMAP_DRAW_DIRECT                0x64        // Draw bitmap on the go

// todo : bitmap file structure


// ---        9-slice  commands        ---

#define GLK_9SLICE_UPLOAD_FILE0                0x5c        // Upload 9-slice file (byte 0)
#define GLK_9SLICE_UPLOAD_FILE1                0x03        // Upload 9-slice file (byte 1)
#define GLK_9SLICE_UPLOAD_MASK0                0x5c        // Upload 9-slice mask (byte 0)
#define GLK_9SLICE_UPLOAD_MASK1                0x06        // Upload 9-slice mask (byte 1)
#define GLK_9SLICE_DRAW                        0x5B        // Draw 9-slice


// ---        Animation  commands        ---

#define GLK_ANIM_UPLOAD0                    0x5C        // Upload animation file (byte 0)
#define GLK_ANIM_UPLOAD1                    0x5C        // Upload animation file (byte 0)
#define GLK_ANIM_DISPLAY                    0xC1        // Display animation
#define GLK_ANIM_DELETE                        0xC7        // Delete animation
#define GLK_ANIM_START_STOP                    0xC2        // Start/Stop animation
#define GLK_ANIM_SET                        0xC5        // Set animation frame
#define GLK_ANIM_GET                        0xC4        // Get animation frame


// ---        General Purpose output  commands        ---

#define GLK_GPO_ON                            0x56        // General Purpose Output On
#define GLK_GPO_OFF                            0x57        // General Purpose Output Off
#define GLK_GPO_SET_STARTUP                    0xC3        // Set Start Up GPO State
#define GLK_GPO_SET_LED                        0x5A        // Set LED Indicators


// ---        One wire commands  commands        ---

#define GLK_1WIRE                            0xC8        // 1 wire command byte
#define GLK_1WIRE_SEARCH                    0x02        // Search for a One-Wire Device
#define GLK_1WIRE_TRANSACT                    0x01        // Dallas One-Wire Transaction


// ---        Piezo buzzer  commands        ---

#define GLK_BUZZ_ON                            0xBB        // Activate Piezo Buzzer
#define GLK_BUZZ_BEEP                        0xBC        // Set Default Buzzer Beep
#define GLK_BUZZ_KEY                        0xB6        // Set Keypad Buzzer Beep


// ---        Key  commands        ---

#define GLK_KEY_AUTOTX_ON                    0x41        // Auto Transmit Key Presses On
#define GLK_KEY_AUTOTX_OFF                    0x47        // Auto Transmit Key Presses Off
#define GLK_KEY_POLL                        0x26        // Poll Key Press
#define GLK_KEY_CLEARBUF                    0x45        // Clear Key Buffer
#define GLK_KEY_DEBOUNCE_TIME                0x55        // Set Debounce Time
#define GLK_KEY_REPEAT_OFF                    0x60        // Auto Repeat Mode Off
#define GLK_KEY_ASSIGN_CODES                0xD5        // Assign Keypad Codes
#define GLK_KEY_BACKLIGHT_OFF                0x98        // Keypad Backlight Off
#define GLK_KEY_BRIGHTNESS                    0x9C        // Set Keypad Brightness
#define GLK_KEY_AUTO_BACKLIGHT                0x9D        // Set Auto Backlight
#define GLK_KEY_TYPEMATIC_DELAY                0x9F        // Set Typematic Delay
#define GLK_KEY_TYPEMATIC_INTERVAL            0x9E        // Set Typematic Interval


// ---        Display  commands        ---

#define GLK_DISP_BACKLIGHT_ON                0x42        // Backlight On
#define GLK_DISP_BACKLIGHT_OFF                0x46        // Backlight Off
#define GLK_DISP_SET_BRIGHTNESS                0x99        // Set Brightness
#define GLK_DISP_SETSAVE_BRIGHTNESS            0x98        // Set and Save Brightness
#define GLK_DISP_SET_CONTRAST                0x50        // Set Contrast
#define GLK_DISP_SETSAVE_CONTRAST            0x91        // Set and Save Contrast


// ---        Script  commands        ---

#define GLK_SCRIPT_UPLOAD0                    0x5C        // Upload a Script File (byte 0)
#define GLK_SCRIPT_UPLOAD1                    0x02        // Upload a Script File (byte 1)
#define GLK_SCRIPT_SET                        0x8D        // Set Scripted Key
#define GLK_SCRIPT_RUN                        0x5D        // Run Script File


// ---        Filesystem  commands        ---

#define GLK_FSYS_ERASE_ALL0                    0x21        // Delete Filesystem (byte 0)
#define GLK_FSYS_ERASE_ALL1                    0x59        // Delete Filesystem (byte 1)
#define GLK_FSYS_ERASE_ALL2                    0x21        // Delete Filesystem (byte 2)
#define GLK_FSYS_DEL                        0xAD        // Delete a File
#define GLK_FSYS_SPACE                        0xAF        // Get Filesystem Space
#define GLK_FSYS_DIR                        0xB3        // Get Filesystem Directory
#define GLK_FSYS_UPLOAD                        0xB0        // Filesystem Upload
#define GLK_FSYS_DWL_ALL                    0x30        // Filesystem Download
#define GLK_FSYS_DWL                        0xB2        // File Download
#define GLK_FSYS_MOVE                        0xB4        // File Move
#define GLK_FSYS_XMODEM_UPLOAD_ALL            0xDB        // XModem Filesystem Upload
#define GLK_FSYS_XMODEM_DWL_ALL                0xDE        // XModem Filesystem Download
#define GLK_FSYS_XMODEM_UPLOAD                0xDC        // XModem File Upload
#define GLK_FSYS_XMODEM_DWL                    0xDD        // XModem File Download
#define GLK_FSYS_XMODEM1                    0x85        // XModem cmd (byte 1) (byte 0 is xmodem command)
#define GLK_FSYS_XMODEM2                    0x06        // XModem cmd (byte 2)
#define GLK_FSYS_XMODEM3                    0x30        // XModem cmd (byte 3)


// ---        Data security  commands        ---

#define GLK_SET_REMEMBER                    0x147        // Set Remember
#define GLK_SET_DATALOCK                    0x202        // Set Data Lock
#define GLK_SETSAVEDATALOCK                    0x203        // Set and Save Data Lock
#define GLK_SET_DATALOCK1                    0x245        // Data lock byte 1 (byte 0 is set or set&save)
#define GLK_SET_DATALOCK2                    0x160        // Data lock byte 2


// ---        Misc  commands        ---

#define GLK_MISC_WDATA                        0x34        // Write Customer Data
#define GLK_MISC_RDATA                        0x35        // Read Customer Data
#define GLK_MISC_WSCRPAD                    0xCC        // Write to Scratchpad
#define GLK_MISC_RSCRPAD                    0xCD        // Read from Scratchpad
#define GLK_MISC_VERSION                    0x36        // Read Version Number
#define GLK_MISC_MODULETYPE                    0x37        // Read Module Type
#define GLK_MISC_SCREEN                        0xB8        // Read Screen




/********************************************************
        Fonctions
*********************************************************/

void glk_init( void );
int  glk_open( void );
int  glk_close( void );

#endif /* GLK_H_ */


 
