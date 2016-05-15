//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "Log.hpp"
#include "StreamLogger.hpp"

namespace Bell { namespace Log {

	namespace {
		std::shared_mutex mutex_;
		std::shared_ptr<Logger> globalLogger_ = StreamLogger::stdErr();
	}

	//	グローバルロガーの取得
	std::shared_ptr<Logger> globalLogger() noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex_ };
		return globalLogger_;
	}

	//	グローバルロガーの設定
	void globalLogger(std::shared_ptr<Logger> logger) noexcept
	{
		assert(logger);

		auto lock = std::unique_lock<std::shared_mutex> { mutex_ };
		globalLogger_ = logger;
	}

	//	出力レベルの取得
	LogLevel globalLogLevel() noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex_ };
		return globalLogger_->level();
	}

	//	出力レベルの設定
	void globalLogLevel(LogLevel level) noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex_ };
		globalLogger_->level(level);
	}

}}	//	namespace Bell::Log
