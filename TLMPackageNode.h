//
//  TLMPackageNode.h
//  PackageOutline
//
//  Created by Adam Maxwell on 12/22/08.
/*
 This software is Copyright (c) 2008-2016
 Adam Maxwell. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 - Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 - Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in
 the documentation and/or other materials provided with the
 distribution.
 
 - Neither the name of Adam Maxwell nor the names of any
 contributors may be used to endorse or promote products derived
 from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Cocoa/Cocoa.h>
#import "TLMPackage.h"

@class TLMDatabasePackage;

@interface TLMPackageNode : NSObject <TLMInfo>
{
@private
    NSString           *_name;
    NSString           *_fullName;
    NSString           *_shortDescription;
    BOOL                _installed;
    BOOL                _hasParent;
    BOOL                _hasMixedStatus;
    NSMutableArray     *_children;
    TLMDatabasePackage *_package;
}

- (BOOL)matchesSearchString:(NSString *)searchTerm;
- (NSUInteger)numberOfChildren;
- (id)childAtIndex:(NSUInteger)anIndex;
- (void)addChild:(id)aChild;

@property (readwrite, copy) NSString *name;
@property (readwrite, copy) NSString *fullName;
@property (readwrite, copy) NSString *shortDescription; // may be nil
@property (readwrite) BOOL hasParent;
@property (readonly) NSString *status;

@property (readwrite, retain) TLMDatabasePackage *package;

// returns YES if children have mixed installed/uninstalled status
@property (readonly) BOOL hasMixedStatus;
@property (readwrite, getter=isInstalled) BOOL installed;

@end
