/*
   Copyright (c) 2019-2020, Triad National Security, LLC. All rights reserved.

   This is open source software; you can redistribute it and/or modify it
   under the terms of the BSD-3 License. If software is modified to produce
   derivative works, such modified software should be clearly marked, so as
   not to confuse it with the version available from LANL. Full text of the
   BSD-3 License can be found in the LICENSE file of the repository.
*/

#include "LL_Helper.hh"
#include "parse_helpers.hh"

LL_Helper::LL_Helper(Raw_Lines &&buf) noexcept {
  text_.scan_free(buf);
  assert(!text_.lines.empty());
  text_.make_stmts();
}

LL_Helper::LL_Helper(Raw_Lines &&buf, int const last_col) noexcept {
  text_.scan_fixed(buf, last_col);
  assert(!text_.lines.empty());
  text_.make_stmts();
}

std::ostream &LL_Helper::print(std::ostream &os) const {
  for (auto const &l : text_.lines) {
    l.dump(os);
  }
  return os;
}
