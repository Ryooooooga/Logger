//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <gtest/gtest.h>
#include "Bell/Log/StreamLogger.hpp"
#include "Bell/Log/MultiLogger.hpp"

#pragma comment(lib, "gtest/gtest_x86_d.lib")

int main(int argc, char** argv)
{
	auto mult = Bell::Log::MultiLogger();
	auto cout = Bell::Log::StreamLogger::stdErr(Bell::Log::LogLevel::Debug);
	auto cerr = Bell::Log::StreamLogger::stdErr(Bell::Log::LogLevel::Info);

	mult.insertLogger("out", cout);
	mult.insertLogger("err", cerr);
	mult.debug(u8"hoge");
	mult.info(u8"piyo");
	mult.removeLogger("err");
	mult.debug(u8"fuga");
	mult.info(u8"hogera");


	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
