//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <memory>
#include "Logger.hpp"

namespace Bell { namespace Log {

	/**
	 * @brief      グローバルロガーの取得
	 *
	 * @return     グローバルロガー
	 */
	std::shared_ptr<Logger> globalLogger() noexcept;

	/**
	 * @brief      グローバルロガーの設定
	 *
	 * @param[in]  logger  設定するロガー
	 */
	void globalLogger(std::shared_ptr<Logger> logger) noexcept;

	/**
	 * @brief      スレッドローカルロガーの取得
	 *
	 * @return     スレッドローカルロガー
	 */
	std::shared_ptr<Logger> threadLocalLogger() noexcept;

	/**
	 * @brief      グローバルロガーの設定
	 *
	 * @param[in]  logger  設定するロガー
	 */
	void threadLocalLogger(std::shared_ptr<Logger> logger) noexcept;

	/**
	 * @brief      trace出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void trace(std::string format, Args&&... args);

	/**
	 * @brief      debug出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void debug(std::string format, Args&&... args);

	/**
	 * @brief      info出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void info(std::string format, Args&&... args);

	/**
	 * @brief      warning出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void warning(std::string format, Args&&... args);

	/**
	 * @brief      error出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void error(std::string format, Args&&... args);

	/**
	 * @brief      fatal出力
	 *
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void fatal(std::string format, Args&&... args);


	/**
	 * @brief      ログ出力
	 *
	 * @param[in]  level    出力レベル
	 * @param[in]  format   出力文字列フォーマッタ
	 * @param[in]  args...
	 *
	 * @tparam     Args
	 */
	template <typename... Args>
	void write(LogLevel level, std::string format, Args&&... args);

	/**
	 * @brief      ログ出力
	 *
	 * @param[in]  entry  出力する情報
	 */
	void write(const LogEntry& entry);

}}	//	namespace Bell::Log

#include "Log.inl"
