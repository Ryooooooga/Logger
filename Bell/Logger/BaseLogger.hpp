//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "LogLevel.hpp"

namespace Bell { namespace Logger {

	struct LogEntry;

	class BaseLogger
	{
	public:
		virtual ~BaseLogger() noexcept =default;

		/**
		 * @brief      ログ出力レベルの変更
		 *
		 * @param[in]  level  設定するログレベル
		 */
		virtual void level(LogLevel level) noexcept =0;

		/**
		 * @brief      現在のログ出力の取得
		 *
		 * @return     ログレベル
		 */
		virtual LogLevel level() const noexcept =0;

	protected:
		/**
		 * @brief      ログメッセージを出力する
		 *
		 * @param[in]  entry  出力するログ情報
		 */
		virtual void writeLogMessage(const LogEntry& entry) =0;
	};

}}	//	namespace Bell::Logger
