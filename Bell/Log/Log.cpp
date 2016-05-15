//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "Log.hpp"
#include "NullLogger.hpp"
#include "StreamLogger.hpp"

namespace Bell { namespace Log {

	namespace {
		std::shared_mutex mutex_;
		std::shared_ptr<Logger> globalLogger_ = std::make_shared<NullLogger>();
		thread_local std::shared_ptr<Logger> threadLocalLogger_ = StreamLogger::stdErr();
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
		auto lock = std::unique_lock<std::shared_mutex> { mutex_ };
		globalLogger_ = logger;
	}


	//	スレッドローカルロガーの設定
	std::shared_ptr<Logger> threadLocalLogger() noexcept
	{
		return threadLocalLogger_;
	}

	//	スレッドローカルロガーの設定
	void threadLocalLogger(std::shared_ptr<Logger> logger) noexcept
	{
		threadLocalLogger_ = logger;
	}

}}	//	namespace Bell::Log
