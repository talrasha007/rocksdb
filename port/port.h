//  Copyright (c) 2013, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//
// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef STORAGE_LEVELDB_PORT_PORT_H_
#define STORAGE_LEVELDB_PORT_PORT_H_

#include <string.h>

// Include the appropriate platform specific file below.  If you are
// porting to a new platform, see "port_example.h" for documentation
// of what the new port_<platform>.h file must provide.
#if defined(ROCKSDB_PLATFORM_POSIX)
#  include "port/port_posix.h"
#endif

#ifdef CYGWIN
#include <stdlib.h>
#include <sstream>
#define fileno __sfileno
#define fread_unlocked fread
#include "port/port_posix.h"

namespace std {
	template <class Tdigit>
	string to_string(Tdigit value)
	{
		stringstream stream;
		stream << value;
		return stream.str();
	}

	inline int stoi(const string& str)
	{
		return ::atoi(str.c_str());
	}

	inline int stol(const string& str)
	{
		return ::atol(str.c_str());
	}

	inline int stod(const string& str)
	{
		return ::strtod(str.c_str(), NULL);
	}

	inline uint32_t stoul(const string& str)
	{
		return ::strtoul(str.c_str(), NULL, 10);
	}

	inline uint64_t stoull(const string& str)
	{
		return ::strtoull(str.c_str(), NULL, 10);
	}
}
#endif

#endif  // STORAGE_LEVELDB_PORT_PORT_H_
