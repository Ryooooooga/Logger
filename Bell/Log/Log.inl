//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

namespace Bell { namespace Log {

	//	trace
	template <typename... Args>
	void trace(std::string format, Args&&... args)
	{
		threadLocalLogger()->trace(std::move(format), std::forward<Args>(args)...);
	}

	//	debug
	template <typename... Args>
	void debug(std::string format, Args&&... args)
	{
		threadLocalLogger()->debug(std::move(format), std::forward<Args>(args)...);
	}

	//	info
	template <typename... Args>
	void info(std::string format, Args&&... args)
	{
		threadLocalLogger()->info(std::move(format), std::forward<Args>(args)...);
	}

	//	warning
	template <typename... Args>
	void warning(std::string format, Args&&... args)
	{
		threadLocalLogger()->warning(std::move(format), std::forward<Args>(args)...);
	}

	//	error
	template <typename... Args>
	void error(std::string format, Args&&... args)
	{
		threadLocalLogger()->error(std::move(format), std::forward<Args>(args)...);
	}

	//	fatal
	template <typename... Args>
	void fatal(std::string format, Args&&... args)
	{
		threadLocalLogger()->fatal(std::move(format), std::forward<Args>(args)...);
	}

	//	ログ出力
	template <typename... Args>
	void write(LogLevel level, std::string format, Args&&... args)
	{
		threadLocalLogger()->write(level, std::move(format), std::forward<Args>(args)...);
	}

	//	出力
	inline void write(const LogEntry& entry)
	{
		threadLocalLogger()->write(entry);
	}

}}	//	namespace Bell::Logger
