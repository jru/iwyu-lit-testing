//===--- ms_inline_asm.cc - test input file for iwyu ----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This file is not strictly an IWYU test, it just checks that the parser
// doesn't choke on Microsoft inline assembly on any of our target platforms.
// Requires -fms-extensions.

// RUN: %iwyu -Xiwyu --verbose=3 -I . -fms-extensions %s 2>&1 | %chk --check-prefix=IWYU %s
// RUN: %iwyu -Xiwyu --verbose=3 -fms-extensions %s 2>&1 | %chk --check-prefix=IWYU %s

int main() {
  int r;
  __asm {
    // TODO: Add a use here, e.g. by using IndirectClass::statica
    // when/if we ever support IWYU analysis inside inline assembly.
    mov ecx, 0
    mov r, ecx
  };

  return r;
}

// IWYU: ms_inline_asm.cc has correct #includes/fwd-decls
