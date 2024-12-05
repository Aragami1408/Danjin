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

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define DANJIN_PLATFORM_WINDOWS
	#ifndef _WIN64
		#error "64-bit is required on Windows!"
	#endif
#elif defined(__linux__) || defined(__gnu_linux__)
	#define DANJIN_PLATFORM_LINUX
#elif __APPLE__
	#define DANJIN_PLATFORM_APPLE
	#include <TargetConditionals.h>
#else
	#error "Unknown platform!"
#endif

#ifdef DANJIN_PLATFORM_WINDOWS
	#ifdef DANJIN_EXPORT
		#define DANJIN_API __declspec(dllexport)
	#else
		#define DANJIN_API __declspec(dllimport)
	#endif
#else
	#ifdef DANJIN_EXPORT
		#define DANJIN_API __attribute__((visibility("default")))
	#else
		#define DANJIN_API
	#endif
#endif

#ifdef DANJIN_ENABLE_ASSERTS
	#define DANJIN_ASSERT(x, ...) { if(!(x)) { DANJIN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DANJIN_CORE_ASSERT(x, ...) { if(!(x)) { DANJIN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DANJIN_ASSERT(x, ...)
	#define DANJIN_CORE_ASSERT(x, ...)
#endif
