//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <fmt/format.h>
#include "../Timer/Stopwatch.hpp"

namespace Bell::Log {

	//	read lock
	inline std::shared_lock<std::shared_mutex> Logger::readLock() const noexcept
	{
		return std::shared_lock<std::shared_mutex> { mutex_ };
	}

	//	write lock
	inline std::unique_lock<std::shared_mutex> Logger::writeLock() const noexcept
	{
		return std::unique_lock<std::shared_mutex> { mutex_ };
	}

	//	trace
	template <typename... Args>
	void Logger::trace(std::string format, Args&&... args)
	{
		write(LogLevel::Trace, std::move(format), std::forward<Args>(args)...);
	}

	//	debug
	template <typename... Args>
	void Logger::debug(std::string format, Args&&... args)
	{
		write(LogLevel::Debug, std::move(format), std::forward<Args>(args)...);
	}

	//	info
	template <typename... Args>
	void Logger::info(std::string format, Args&&... args)
	{
		write(LogLevel::Info, std::move(format), std::forward<Args>(args)...);
	}

	//	warning
	template <typename... Args>
	void Logger::warning(std::string format, Args&&... args)
	{
		write(LogLevel::Warning, std::move(format), std::forward<Args>(args)...);
	}

	//	error
	template <typename... Args>
	void Logger::error(std::string format, Args&&... args)
	{
		write(LogLevel::Error, std::move(format), std::forward<Args>(args)...);
	}

	//	fatal
	template <typename... Args>
	void Logger::fatal(std::string format, Args&&... args)
	{
		write(LogLevel::Fatal, std::move(format), std::forward<Args>(args)...);
	}

	//	ログ出力
	template <typename... Args>
	void Logger::write(LogLevel level, std::string format, Args&&... args)
	{
		static const Timer::HiresolutionStopwatch stopwatch;

		write(LogEntry {
			level,
			std::this_thread::get_id(),
			stopwatch.elapsed(),
			fmt::format(format, std::forward<Args>(args)...),
		});
	}

	//	出力
	inline void Logger::write(const LogEntry& entry)
	{
		auto lock = writeLock();

		if (entry.level >= level_)
		{
			writeLogMessage(entry);
		}
	}

	//	出力レベル設定
	inline void Logger::level(LogLevel level) noexcept
	{
		auto lock = writeLock();
		level_ = level;
	}

	//	出力レベル取得
	inline LogLevel Logger::level() const noexcept
	{
		auto lock = readLock();
		return level_;
	}

}	//	namespace Bell::Logger
