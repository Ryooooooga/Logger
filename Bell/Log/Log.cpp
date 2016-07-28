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

namespace Bell::Log {

	namespace {

		//	mutex
		std::shared_mutex mutex;

		//	グローバルインスタンス
		std::shared_ptr<Logger> globalInstance;

		//	グローバルインスタンスの取得
		std::shared_ptr<Logger> getGlobalInstance()
		{
			static std::shared_ptr<Logger> defaultInstance = StreamLogger::stdErr();
			return globalInstance ? globalInstance : defaultInstance;
		}

	}

	//	グローバルロガーの取得
	std::shared_ptr<Logger> globalLogger() noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex };
		return getGlobalInstance();
	}

	//	グローバルロガーの設定
	void globalLogger(std::shared_ptr<Logger> logger) noexcept
	{
		auto lock = std::unique_lock<std::shared_mutex> { mutex };
		getGlobalInstance() = logger;
	}

	//	出力レベルの取得
	LogLevel globalLogLevel() noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex };
		return getGlobalInstance()->level();
	}

	//	出力レベルの設定
	void globalLogLevel(LogLevel level) noexcept
	{
		auto lock = std::shared_lock<std::shared_mutex> { mutex };
		getGlobalInstance()->level(level);
	}

}	//	namespace Bell::Log
