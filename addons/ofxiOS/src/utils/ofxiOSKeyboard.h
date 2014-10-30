/*
 *  ofIphoneKeyboard.h
 *
 *  Created by Zach Gage on 3/1/09.
 *  Copyright 2009 stfj. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import "ofMain.h"
#import "ofxiOSExtras.h"
#pragma once

struct ofxiOSKeyboardMoveEventArgs
{
	float width;
	float height;
};

@interface ofxiOSKeyboardDelegate : NSObject <UITextFieldDelegate>
{
	UITextField*			_textField;
	bool					open;
	int						_x;
	int						_y;
	int						_w;
	int						_h;
	int						_xOriginal;
	int						_yOriginal;
	int						fieldLength;
	ofEvent<void>			eventReturnClicked;
	ofEvent<ofxiOSKeyboardMoveEventArgs> eventWillShow;
	ofEvent<ofxiOSKeyboardMoveEventArgs> eventDidShow;
	ofEvent<ofxiOSKeyboardMoveEventArgs> eventWillHide;
	ofEvent<ofxiOSKeyboardMoveEventArgs> eventDidHide;
}
- (id) init: (int)x y:(int)y width:(int)w height:(int)h;
- (void) showText;
- (void) hideText;
- (const char *) getText;
- (const char*) getLabelText;
- (void) setText: (NSString *)text;
- (void) setFontSize: (int)size;
- (void) setFontColorRed: (int)r green: (int)g blue:(int)b alpha:(int)a;
- (void) setBgColorRed: (int)r green: (int)g blue:(int)b alpha:(int)a;
- (bool) isKeyboardShowing;
- (void) setFrame: (CGRect) rect;
- (void) setPlaceholder: (NSString *)text;
- (void) openKeyboard;
- (void) closeKeyboard;
- (void) updateOrientation;
- (void) makeSecure;
- (void) setFieldLength: (int)len;
- (UITextField *)getTextField;

- (ofEvent<void>&) getReturnClickedEvent;
- (ofEvent<ofxiOSKeyboardMoveEventArgs>&) getWillShowEvent;
- (ofEvent<ofxiOSKeyboardMoveEventArgs>&) getDidShowEvent;
- (ofEvent<ofxiOSKeyboardMoveEventArgs>&) getWillHideEvent;
- (ofEvent<ofxiOSKeyboardMoveEventArgs>&) getDidHideEvent;
- (void) keyboardWillShow: (NSNotification*)aNotification;
- (void) keyboardDidShow: (NSNotification*)aNotification;
- (void) keyboardWillHide: (NSNotification*)aNotification;
- (void) keyboardDidHide: (NSNotification*)aNotification;


@end

#define ofxiPhoneKeyboardDelegate ofxiOSKeyboardDelegate

class ofxiOSKeyboard 
{
	
public:
	
	ofxiOSKeyboard(int _x, int _y, int _w, int _h);
	~ofxiOSKeyboard();
	
	void setVisible(bool visible);
	
	void setPosition(int _x, int _y);
	void setSize(int _w, int _h);
	void setFontSize(int ptSize);
	void setFontColor(int r, int g, int b, int a);
	void setBgColor(int r, int g, int b, int a);
	void setText(string _text);
	void setPlaceholder(string _text);
	void openKeyboard();
	void closeKeyboard();
	void updateOrientation();
	void makeSecure();
	void setMaxChars(int max);
	
	string getText();
    OF_DEPRECATED_MSG("Use getText() instead.", string getLabelText());
	bool isKeyboardShowing();
	
    UITextField * getKeyboardTextField();
	
	ofEvent<void>& getReturnEvent();

protected:
	
	ofxiOSKeyboardDelegate *	keyboard;
	int x,y,w,h;
};

#define ofxiPhoneKeyboard ofxiOSKeyboard

