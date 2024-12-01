#pragma once

#include <cstdint>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef size_t usize;

#ifdef DANJIN_PLATFORM_WINDOWS
	#ifdef DANJIN_BUILD_DLL
		#define DANJIN_API __declspec(dllexport)
	#else
		#define DANJIN_API __declspec(dllimport)
	#endif
#else
	#error Danjin only support Windows for now
#endif

#ifdef DANJIN_ENABLE_ASSERTS
	#define DANJIN_ASSERT(x, ...) { if(!(x)) { DANJIN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DANJIN_CORE_ASSERT(x, ...) { if(!(x)) { DANJIN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DANJIN_ASSERT(x, ...)
	#define DANJIN_CORE_ASSERT(x, ...)
#endif
