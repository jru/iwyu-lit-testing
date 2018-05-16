//===--- direct.h - test input file for iwyu ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This file is meant to be directly #included by a .cc file.  All it
// does is #include another file (which the .cc file is thus
// #including indirectly).

#ifndef INCLUDE_WHAT_YOU_USE_TESTS_CXX_DIRECT_H_
#define INCLUDE_WHAT_YOU_USE_TESTS_CXX_DIRECT_H_

#include "indirect.h"

#endif  // INCLUDE_WHAT_YOU_USE_TESTS_CXX_DIRECT_H_
