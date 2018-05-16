//===--- array.cc - test input file for iwyu ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Tests that we handle correctly identify a[i] as a full use of a.

// RUN: %iwyu -Xiwyu --verbose=3 -I . %s 2>&1 | %chk --check-prefix=IWYU %s

#include "direct.h"

class A {
  // IWYU: IndirectClass needs a declaration
  IndirectClass *getIndirectClass(int i) {
    // IWYU: IndirectClass is.*indirect\.h
    (void) sizeof(_b[i]);     // requires full type
    // IWYU: IndirectClass is.*indirect\.h
    // IWYU-NEXT: IndirectClass needs a declaration
    (void) sizeof(&(_b[i]));  // requires full type
    // IWYU: IndirectClass is.*indirect\.h
    return &(_b[i]);
  }
  // IWYU: IndirectClass needs a declaration
  IndirectClass *_b;
};


// IWYU: array.cc should add these lines:
// IWYU-NEXT: #include "indirect.h"

// IWYU: array.cc should remove these lines:
// IWYU-NEXT: - #include "direct.h"  // lines

// IWYU: The full include-list for .*/array.cc:
// IWYU-NEXT: #include "indirect.h"  // for IndirectClass
