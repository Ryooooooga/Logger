//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <fstream>
#include <boost/utility/string_view.hpp>
#include "StreamLogger.hpp"

namespace Bell::Log {

	/**
	 * @brief      ファイルロガー
	 */
	class FileLogger
		: public StreamLogger
	{
		std::string		fileName_;
		std::ofstream	file_;

	public:
		/**
		 * @brief      FileLogger ctor
		 *
		 * @param[in]  path           出力ファイル名
		 * @param[in]  level          出力レベル
		 * 
		 * @throws     runtime_error  ファイルが開けなかった場合
		 */
		explicit FileLogger(std::string path, LogLevel level = LogLevel::All);

		/**
		 * @brief      ログファイル名
		 *
		 * @return     ファイル名
		 */
		boost::string_view fileName() const noexcept;
	};

}	//	namespace Bell::Log
