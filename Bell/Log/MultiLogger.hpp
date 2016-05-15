//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <unordered_map>
#include "Logger.hpp"

namespace Bell { namespace Log {

	
	class MultiLogger
		: public Logger
	{
	protected:
		std::unordered_map<std::string, std::shared_ptr<Logger>> loggers_;

	public:
		/**
		 * @brief      MultiLogger ctor
		 *
		 * @param[in]  level  出力レベル
		 */
		explicit MultiLogger(LogLevel level = LogLevel::All);

		/**
		 * @brief      ロガーの追加
		 *
		 * @param[in]  name    追加するロガー名
		 * @param[in]  logger  追加するロガー
		 */
		void insertLogger(std::string name, std::shared_ptr<Logger> logger);

		/**
		 * @brief      ロガーの削除
		 *
		 * @param[in]  name  削除するロガーの名前
		 */
		void removeLogger(std::string name);

	protected:
		void writeLogMessage(const LogEntry& entry) override;
	};

}}	//	namespace Bell::Log
