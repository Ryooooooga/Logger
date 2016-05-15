//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "Logger.hpp"

namespace Bell { namespace Log {

	/**
	 * @brief      何もしないロガー
	 */
	class NullLogger
		: public Logger
	{
	public:
		using Logger::Logger;

	protected:
		void writeLogMessage(const LogEntry&) override {}
	};

}}	//	namespace Bell::Log
