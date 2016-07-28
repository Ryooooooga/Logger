//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "LogLevel.hpp"

namespace Bell::Log {

	//	operator <<
	std::ostream& operator <<(std::ostream& stream, LogLevel level)
	{
		switch (level)
		{
			case LogLevel::All		: stream << u8"All"		; break;
			case LogLevel::Trace	: stream << u8"Trace"	; break;
			case LogLevel::Debug	: stream << u8"Debug"	; break;
			case LogLevel::Info		: stream << u8"Info"	; break;
			case LogLevel::Warning	: stream << u8"Warning"	; break;
			case LogLevel::Error	: stream << u8"Error"	; break;
			case LogLevel::Fatal	: stream << u8"Fatal"	; break;
			case LogLevel::Off		: stream << u8"Off"		; break;
		}

		return stream;
	}

}	//	namespace Bell::Logger
