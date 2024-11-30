#pragma once

#include <Danjin/Common.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace Danjin {
class DANJIN_API Logger {
public:
	static void init();

	inline static std::shared_ptr<spdlog::logger> &getCoreLogger() { return s_coreLogger; }
	inline static std::shared_ptr<spdlog::logger> &getClientLogger() { return s_clientLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_coreLogger;
	static std::shared_ptr<spdlog::logger> s_clientLogger;

};
}

#define DANJIN_CORE_TRACE(...)		::Danjin::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define DANJIN_CORE_INFO(...)		::Danjin::Logger::getCoreLogger()->info(__VA_ARGS__)
#define DANJIN_CORE_WARN(...)		::Danjin::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define DANJIN_CORE_ERROR(...)		::Danjin::Logger::getCoreLogger()->error(__VA_ARGS__)
#define DANJIN_CORE_FATAL(...)		::Danjin::Logger::getCoreLogger()->fatal(__VA_ARGS__)

#define DANJIN_TRACE(...)			::Danjin::Logger::getClientLogger()->trace(__VA_ARGS__)
#define DANJIN_INFO(...)			::Danjin::Logger::getClientLogger()->info(__VA_ARGS__)
#define DANJIN_WARN(...)			::Danjin::Logger::getClientLogger()->warn(__VA_ARGS__)
#define DANJIN_ERROR(...)			::Danjin::Logger::getClientLogger()->error(__VA_ARGS__)
#define DANJIN_FATAL(...)			::Danjin::Logger::getClientLogger()->fatal(__VA_ARGS__)
