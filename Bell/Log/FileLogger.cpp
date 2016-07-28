//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "FileLogger.hpp"

namespace Bell::Log {

	//	FileLogger ctor
	FileLogger::FileLogger(std::string path, LogLevel level)
		: StreamLogger(file_, level), fileName_(std::move(path))
	{
		file_.open(fileName_);

		if (!file_)
		{
			throw std::runtime_error { fmt::format(u8"FileLogger: could not open file '{}'", fileName_) };
		}
	}

	//	ファイル名
	boost::string_ref FileLogger::fileName() const noexcept
	{
		return fileName_;
	}

}	//	namespace Bell::Log
