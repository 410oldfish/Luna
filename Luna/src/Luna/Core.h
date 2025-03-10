//
// Created by 47230 on 2025/3/5.
//
#pragma once

#ifdef LUNA_PLATFORM_WINDOWS
    #ifdef LUNA_BUILD_DLL
        #define LUNA_API __declspec(dllexport)
    #else
        #define LUNA_API __declspec(dllimport)
    #endif
#else
    #error Luna only support Windows!
#endif

#ifdef LUNA_ENABLE_ASSERTS
    #define LUNA_ASSERT(x, ...)	{ if(!(x)) {LUNA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
    #define LUNA_CORE_ASSERT(x, ...)	{ if(!(x)) {LUNA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
    #define LUNA_ASSERT(x, ...)
    #define LUNA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define LUNA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)