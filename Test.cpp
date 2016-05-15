//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <gtest/gtest.h>
#include "Bell/Log/FileLogger.hpp"

#pragma comment(lib, "gtest/gtest_x86_d.lib")

int main(int argc, char** argv)
{
	Bell::Log::FileLogger a("a.txt");
	a.fatal(u8"hoge");

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
