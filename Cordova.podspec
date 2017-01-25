{
  "name": "Cordova",
  "version": "1.7.0",
  "summary": "Apache Cordova is a platform for building native mobile applications using HTML, CSS and JavaScript.",
  "homepage": "http://cordova.apache.org/",
  "authors": "Original developed by Nitobi (acquire by Adobe) and all other PhoneGap and Cordova Contributors",
  "license": "Apache License, Version 2.0",
  "source": {
    "git": "https://github.com/BlueTrailSoftware/cordova-ios.git",
    "tag": "1.7.1"
  },
  "source_files": "CordovaLib/Classes/*.{h,m}",
  "resources": [
    "CordovaLib/javascript/*.js",
    "CordovaLib/VERSION"
  ],
  "platforms": {
    "ios": "4.3"
  },
  "requires_arc": false,
  "dependencies": {
    "JSONKit": [
      "https://github.com/BlueTrailSoftware/JSONKit.git",
      "~> 1.4"
    ]
  },
  "frameworks": [
    "AddressBook",
    "AddressBookUI",
    "AudioToolbox",
    "AVFoundation",
    "CoreLocation",
    "MediaPlayer",
    "QuartzCore",
    "SystemConfiguration",
    "MobileCoreServices",
    "CoreMedia",
    "UIKit"
  ]
}
