#pragma once

#include <iostream>

#include <spectrium/macro.hpp>



SPECTRIUM_NAMESPACE_BEGIN


/**
 * @brief Prints any type of data to the stdout.
 *
 * Note that the data needs to be printable.
 *
 * @param data: Any type and amount of data.
 * */
template <typename... T>
void print(const T&... data) noexcept
{
	(std::cout << ... << data);
}


/**
 * @brief Prints any type of data to the stdout. Adds a line break at the end of it.
 *
 * Note that the data needs to be printable.
 *
 * @param data: Any type and amount of data.
 * */
template <typename... T>
void println(const T&... data) noexcept
{
	(std::cout << ... << data) << std::endl;
}


SPECTRIUM_NAMESPACE_END