//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <iostream>
#include <fmt/ostream.h>
#include "StreamLogger.hpp"

#include <boost/utility/string_ref.hpp>

namespace Bell { namespace Log {

	//	標準エラー出力
	std::shared_ptr<StreamLogger> StreamLogger::stdErr(LogLevel level)
	{
		return std::make_shared<StreamLogger>(std::cerr, level);
	}

	//	標準出力
	std::shared_ptr<StreamLogger> StreamLogger::stdOut(LogLevel level)
	{
		return std::make_shared<StreamLogger>(std::cout, level);
	}

	//	StreamLogger ctor
	StreamLogger::StreamLogger(std::ostream& stream, LogLevel level) noexcept
		: Logger(level), stream_(stream) {}

	//	ストリーム
	std::ostream& StreamLogger::stream() const noexcept
	{
		return stream_;
	}

	//	出力
	void StreamLogger::writeLogMessage(const LogEntry& entry)
	{
		stream_ << fmt::format(u8"[{0:^8}][thread:{1:0>8x}]({2:>14.6f}) {3}", entry.level, (int)&entry.threadId, entry.timestamp, entry.message) << std::endl;
	}

}}	//	namespace Bell::Log
