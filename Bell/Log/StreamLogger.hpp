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

namespace Bell::Log {

	/**
	 * @brief      ストリーム出力ロガー
	 */
	class StreamLogger
		: public Logger
	{
		std::ostream& stream_;

	public:
		/**
		 * @brief      標準エラーストリームロガー
		 * 
		 * @param[in]  level  出力レベル
		 *
		 * @return     エラーストリームロガー
		 */
		static std::shared_ptr<StreamLogger> stdErr(LogLevel level = LogLevel::All);

		/**
		 * @brief      標準出力ストリームロガー
		 *
		 * @param[in]  level  出力レベル
		 *
		 * @return     出力ストリームロガー
		 */
		static std::shared_ptr<StreamLogger> stdOut(LogLevel level = LogLevel::All);

		/**
		 * @brief      StreamLogger ctor
		 *
		 * @param      stream  出力先のストリーム
		 * @param[in]  level   出力レベル
		 */
		explicit StreamLogger(std::ostream& stream, LogLevel level = LogLevel::All) noexcept;
		
		/**
		 * @brief      出力先のストリームへの参照の取得
		 *
		 * @return     出力先のストリーム
		 */
		std::ostream& stream() const noexcept;

	protected:
		void writeLogMessage(const LogEntry& entry) override;
	};

}	//	namespace Bell::Log
