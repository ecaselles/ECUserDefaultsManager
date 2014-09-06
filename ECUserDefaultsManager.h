//
//  ECUserDefaultsManager.h
//
//  Copyright (c) 2013 Eduardo Caselles. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 `ECUserDefaultsManager` wraps the main methods to store and retrieve data using the system's `NSUserDefaults`.
 
 `ECUserDefaultsManager` is implemented as a group of class methods, so they can be called through different 
 parts of the app, without having to create instances of the class.

 
 ## Examples of usage:
 
 #import "ECUserDefaultsManager.h"
 
 // Store data
 NSArray *namesToStore = @[@"John", @"Peter", @"Claire"];
 if ([ECUserDefaultsManager saveAppData:namesToStore forKey:@"Names"]) {
    NSLog(@"User info was saved correctly.");
 } else {
    NSLog(@"Error saving user info.");
 }
 
 // Retrieve stored data
 NSArray *storedNames = [ECUserDefaultsManager appDataforKey:@"Names"];
 
 // Remove data
 if ([ECUserDefaultsManager removeAppDataforKey:@"Names"]) {
    NSLog(@"Data was deleted correctly.");
 } else {
    NSLog(@"Error deleting data.");
 }
 
 */

@interface ECUserDefaultsManager : NSObject

#pragma mark - User Defaults Actions

/**
 Stores the given data in `NSUserDefaults` related to the given key.
 The data can be only property list objects: NSData, NSString, NSNumber, NSDate, NSArray, or NSDictionary.
 
 @param data The object to store in the defaults.
 @param key A NSString with the key with which to associate with the data.
 
 @return Returns `YES` on [NSUserDefaults synchronize] success, or `NO` on failure.
 */
+ (BOOL) saveAppData: (id) data forKey: (NSString *)key;


/**
 Returns the object associated with the first occurrence in `NSUserDefaults` of the specified key.
 The returned object is immutable, even if the value you originally set was mutable.
 
 @param key A NSString with the key.
 
 @return Returns the object associated with the specified key, or `nil` if the key was not found.
 */
+ (id) appDataforKey: (NSString *) key;


/**
 Removes the entry related to the given key from `NSUserDefaults`.
 If no records exist in `NSUserDefaults`, this method does nothing.
 
 @param key A NSString with the key.
 
 @return Returns `YES` on [NSUserDefaults synchronize] success, or `NO` on failure.
 */
+ (BOOL) removeAppDataforKey: (NSString *) key;

@end
