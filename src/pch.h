#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <Danjin/Logger.hpp>

#ifdef DANJIN_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif

#ifdef DANJIN_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
