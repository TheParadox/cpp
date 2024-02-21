#ifndef LOG_HPP
#define LOG_HPP

#include <chrono>
#include <string>
#include <vector>

#include "fmt/core.h"
#include "fmt/color.h"
#include "fmt/compile.h"
#include "fmt/chrono.h"

#ifdef PLATFORM_WIN32
	#include <Windows.h>
#endif

using namespace std::literals::chrono_literals;

namespace LOG {
	enum ErrorLevel {
		Trace = 0,
		Info,
		Warn,
		Fault,
		Fatal
	};

	static std::string s_pattern = "[{:%T (%z)}]: ";
	
	static std::vector<fmt::text_style> s_logStyles = {
		fmt::fg(fmt::color::green), 				//TRACE
		fmt::fg(fmt::color::aqua), 					//INFO
		fmt::fg(fmt::color::yellow), 				//WARN
		fmt::fg(fmt::color::orange), 				//FAULT
		fmt::fg(fmt::color::medium_violet_red)	 	//FATAL
	};

	inline void init() {
		#ifdef PLATFORM_WIN32
			//This is to update the WIN32 console to allow FMT to work...
			//Need to happen BEFORE ANY fmt calls are made else it will not work
			//However,  all  of this (especially the console) should be disabled during realise builds...
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD dwMode = 0;
			GetConsoleMode(hOut, &dwMode);
			dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
			SetConsoleMode(hOut, dwMode);
		#endif
	}

	template<typename ... Args>
	inline void PRINT(fmt::format_string<Args...> a_fmt, ErrorLevel a_level, Args... a_args) {
		//Need to determine if there is a better way to handle this -- if one exists...
		//But its not a bottleneck, yet. So no need to worry about it at the moment.

		auto currentTime = std::chrono::time_point_cast<std::chrono::seconds>(
			std::chrono::zoned_time(
				std::chrono::current_zone(),
				std::chrono::system_clock::now()
			).get_local_time());
			currentTime = floor<std::chrono::seconds>(currentTime);

		std::string text = fmt::format(a_fmt, std::forward<Args>(a_args)...);
		fmt::print(s_logStyles[a_level], s_pattern, currentTime);
		fmt::print(s_logStyles[a_level],  text + "\n");
	}
};

#ifdef CALC_DEBUG 
	#define CR_TRACE(fmt, ...) 	::LOG::PRINT(fmt, LOG::ErrorLevel::Trace, __VA_ARGS__)
	#define CR_INFO(fmt, ...) 	::LOG::PRINT(fmt, LOG::ErrorLevel::Info, __VA_ARGS__)
	#define CR_WARN(fmt, ...) 	::LOG::PRINT(fmt, LOG::ErrorLevel::Warn, __VA_ARGS__)
	#define CR_FAULT(fmt, ...) 	::LOG::PRINT(fmt, LOG::ErrorLevel::Fault, __VA_ARGS__)
	#define CR_FATAL(fmt, ...) 	::LOG::PRINT(fmt, LOG::ErrorLevel::Fatal, __VA_ARGS__)
#else
	#define CR_TRACE(...)
	#define CR_INFO(...)
	#define CR_WARN(...)
	#define CR_FAULT(...)
	#define CR_FATAL(...)
#endif

#ifdef CALC_ASSERTS
	#define CR_ASSERT(x, ...) { if(!(x)) { CR_FATAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CR_ASSERT(x, ...)
#endif


#endif //LOG_HPP