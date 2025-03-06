//
// Created by 47230 on 2025/3/6.
//

#ifndef LOG_H
#define LOG_H

#include "spdlog/spdlog.h"
#include "Core.h"
#include "spdlog/fmt/ostr.h"

namespace Luna {
	class LUNA_API Log
    {
          public:
                static void Init();

                inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
				inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

          private:
            	static std::shared_ptr<spdlog::logger> s_CoreLogger;
                static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };

}

//Core Log macros
#define LUNA_CORE_FATAL(...)	:: Luna::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define LUNA_CORE_ERROR(...)	:: Luna::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LUNA_CORE_WARN(...)		:: Luna::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LUNA_CORE_INFO(...)		:: Luna::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LUNA_CORE_TRACE(...)	:: Luna::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log macros
#define LUNA_FATAL(...)		:: Luna::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define LUNA_ERROR(...)		:: Luna::Log::GetClientLogger()->error(__VA_ARGS__)
#define LUNA_WARN(...)		:: Luna::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LUNA_INFO(...)		:: Luna::Log::GetClientLogger()->info(__VA_ARGS__)
#define LUNA_TRACE(...)		:: Luna::Log::GetClientLogger()->trace(__VA_ARGS__)

#endif //LOG_H
