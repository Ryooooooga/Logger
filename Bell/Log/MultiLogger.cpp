//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "MultiLogger.hpp"

namespace Bell { namespace Log {

	//	MultiLogger ctor
	MultiLogger::MultiLogger(LogLevel level)
		: Logger(level) {}

	//	挿入
	void MultiLogger::insertLogger(std::string name, std::shared_ptr<Logger> logger)
	{
		assert(logger);
		assert(logger.get() != this);

		auto lock = writeLock();
		loggers_.emplace(std::move(name), std::move(logger));
	}

	//	削除
	void MultiLogger::removeLogger(std::string name)
	{
		auto lock = writeLock();
		loggers_.erase(std::move(name));
	}

	//	出力
	void MultiLogger::writeLogMessage(const LogEntry& entry)
	{
		for (auto&& x : loggers_)
		{
			x.second->write(entry);
		}
	}

}}	//	namespace Bell::Log
