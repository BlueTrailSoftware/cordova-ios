/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */


#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioServices.h>
#import <AVFoundation/AVFoundation.h>

#import "CDVPlugin.h"




typedef NS_ENUM (NSUInteger, CDVMediaError) {
	MEDIA_ERR_ABORTED = 1,
	MEDIA_ERR_NETWORK = 2,
	MEDIA_ERR_DECODE = 3,
	MEDIA_ERR_NONE_SUPPORTED = 4
};

typedef NS_ENUM(NSUInteger, CDVMediaStates) {
	MEDIA_NONE = 0,
	MEDIA_STARTING = 1,
	MEDIA_RUNNING = 2,
	MEDIA_PAUSED = 3,
	MEDIA_STOPPED = 4
};

typedef NS_ENUM (NSUInteger, CDVMediaMsg) {
	MEDIA_STATE = 1,
	MEDIA_DURATION = 2,
    MEDIA_POSITION = 3,
	MEDIA_ERROR = 9
};

@interface CDVAudioPlayer : AVAudioPlayer
{
	NSString* mediaId;
}
@property (nonatomic,copy) NSString* mediaId;
@end

#ifdef __IPHONE_3_0
@interface CDVAudioRecorder : AVAudioRecorder
{
	NSString* mediaId;
}
@property (nonatomic,copy) NSString* mediaId;
@end
#endif
	
@interface CDVAudioFile : NSObject
{
	NSString* resourcePath;
	NSURL* resourceURL;
	CDVAudioPlayer* player;
#ifdef __IPHONE_3_0
	CDVAudioRecorder* recorder;
#endif
}

@property (nonatomic, retain) NSString* resourcePath;
@property (nonatomic, retain) NSURL* resourceURL;
@property (nonatomic, retain) CDVAudioPlayer* player;

#ifdef __IPHONE_3_0
@property (nonatomic, retain) CDVAudioRecorder* recorder;
#endif

@end

@interface CDVSound : CDVPlugin <AVAudioPlayerDelegate, AVAudioRecorderDelegate>
{
	NSMutableDictionary* soundCache;
    AVAudioSession* avSession;
}
@property (nonatomic, retain) NSMutableDictionary* soundCache;
@property (nonatomic, retain) AVAudioSession* avSession;
//DEPRECATED
- (void) play:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));	  	
- (void) pause:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
- (void) stop:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
// DEPRECATED

- (void) startPlayingAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) pausePlayingAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) stopPlayingAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) seekToAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) release:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) getCurrentPositionAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

// DEPRECATED
- (void) getCurrentPosition:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
- (void) prepare:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
// DEPRECATED

- (BOOL) hasAudioSession;

// helper methods
- (CDVAudioFile*) audioFileForResource:(NSString*) resourcePath withId: (NSString*)mediaId;
- (BOOL) prepareToPlay: (CDVAudioFile*) audioFile withId: (NSString*)mediaId;
- (NSString*) createMediaErrorWithCode: (CDVMediaError) code message: (NSString*) message;

// DEPRECATED
- (void) startAudioRecord:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
- (void) stopAudioRecord:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options __attribute__((deprecated));
// DEPRECATED

- (void) startRecordingAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) stopRecordingAudio:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

@end
