#pragma once

#include <string>

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>

#include <ctgmath>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <iostream>
#include <sstream>

#include <thread>
#include <mutex>

#include <Windows.h>

#define NOW (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count())

namespace Console3D{
	namespace type {

		typedef int8_t byte;
		typedef uint8_t ubyte;
		typedef uint16_t uint;
		typedef uint64_t ulong;

		using c_int = const int&;
		using c_char = const char&;
		using c_long = const long&;
		using c_float = const float&;
		using c_double = const double&;
		using c_size = const size_t&;

		using c_string = const std::string&;

		using c_uint = const uint&;
		using c_ulong = const ulong&;

		using c_byte = const byte&;
		using c_ubyte = const ubyte&;

	}
}