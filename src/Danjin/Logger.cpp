#include <pch.h>
#include <Danjin/Logger.hpp>

namespace Danjin {
std::shared_ptr<spdlog::logger> Logger::s_coreLogger;
std::shared_ptr<spdlog::logger> Logger::s_clientLogger;

void Logger::init() {
	spdlog::set_pattern("%^[%Y/%m/%d %T - %l] %n: %v%$");

	s_coreLogger = spdlog::stdout_color_mt("DANJIN-CORE");
	s_coreLogger->set_level(spdlog::level::trace);

	s_clientLogger = spdlog::stdout_color_mt("DANJIN-APP");
	s_clientLogger->set_level(spdlog::level::trace);
}
}
