//===--- array.cc - test input file for iwyu ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Tests that we handle correctly identify a[i] as a full use of a.

// RUN: %iwyu -Xiwyu --verbose=3 -I . %s 2>&1 | %chk %s

#include "direct.h"

class Type {};

class A {
  // IWYU: IndirectClass needs a declaration
  IndirectClass *getIndirectClass(int i) {

    // IWYU: IndirectClass is.*indirect\.h
    Type t;

    /// The line above is annotated with a warning that refers to this line
    /// but OutputCheck doesn't care. I only checks the order of directives.
    (void) sizeof(_b[i]);     // requires full type

    /// Missing check doesn't make it fail
    return &(_b[i]);
  }
  // IWYU: IndirectClass needs a declaration
  IndirectClass *_b;
};

/// Missing summary doesn't make it fail either

