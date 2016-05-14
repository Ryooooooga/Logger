//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <string>
#include <thread>
#include "LogLevel.hpp"

namespace Bell { namespace Logger {

	/**
	 * @brief      ログ出力情報
	 */
	struct LogEntry
	{
		LogLevel		level;
		double			timestamp;
		std::thread::id	threadId;
		std::string		message;
	};

}}	//	namespace Bell::Logger
