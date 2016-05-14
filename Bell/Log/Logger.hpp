//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <string>
#include "LogLevel.hpp"

namespace Bell { namespace Log {

	struct LogEntry;

	class Logger
	{
		LogLevel level_;

	public:
		virtual ~Logger() noexcept =default;

		template <typename... Args>
		void trace(std::string format, Args&&... args);

		template <typename... Args>
		void debug(std::string format, Args&&... args);

		template <typename... Args>
		void info(std::string format, Args&&... args);

		template <typename... Args>
		void warning(std::string format, Args&&... args);

		template <typename... Args>
		void error(std::string format, Args&&... args);

		template <typename... Args>
		void fatal(std::string format, Args&&... args);

		template <typename... Args>
		void write(LogLevel level, std::string format, Args&&... args);

		/**
		 * @brief      ログ出力レベルの変更
		 *
		 * @param[in]  level  設定するログレベル
		 */
		void level(LogLevel level) noexcept;

		/**
		 * @brief      現在のログ出力の取得
		 *
		 * @return     ログレベル
		 */
		LogLevel level() const noexcept;

	protected:
		/**
		 * @brief      ログメッセージを出力する
		 *
		 * @param[in]  entry  出力するログ情報
		 */
		virtual void writeLogMessage(const LogEntry& entry) =0;
	};

}}	//	namespace Bell::Logger