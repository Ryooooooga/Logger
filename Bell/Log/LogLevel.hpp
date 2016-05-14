//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <cstdint>

namespace Bell { namespace Log {

	/**
	 * @brief      ログ出力レベル
	 */
	enum class LogLevel
		: std::int32_t
	{
		All,
		Trace,
		Debug,
		Info,
		Warning,
		Error,
		Fatal,
		Off,
	};

}}	//	namespace Bell::Logger