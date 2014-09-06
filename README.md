ECUserDefaultsManager
===================

`ECUserDefaultsManager` is a very easy-to-use and simple wrapper to interact with `NSUserDefaults`. 
It comes with a set of methods for the most common operations done with `NSUserDefaults` (to **store**,
to **retrieve** and to **remove** data from them).
 
`ECUserDefaultsManager` is implemented as a group of class methods, so they can be called through different 
 parts of the app, without having to create instances of the class.

 
Usage
=====
```Objective-C
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
```


License
=======

`ECUserDefaultsManager` is available under the MIT license. See the LICENSE file for more info.
