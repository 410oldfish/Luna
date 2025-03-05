//
// Created by 47230 on 2025/3/5.
//

#ifndef CORE_H
#define CORE_H

#ifdef LUNA_PLATFORM_WINDOWS
    #ifdef LUNA_BUILD_DLL
        #define LUNA_API __declspec(dllexport)
    #else
        #define LUNA_API __declspec(dllimport)
    #endif
#else
    #error Luna only support Windows!
#endif

#endif //CORE_H
