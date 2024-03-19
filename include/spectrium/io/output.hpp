#pragma once

#include <iostream>

#include <spectrium/macro.hpp>



SPECTRIUM_NAMESPACE_BEGIN


template <typename... T>
void print(const T&... data) noexcept
{
	(std::cout << ... << data);
}


template <typename... T>
void println(const T&... data) noexcept
{
	(std::cout << ... << data) << std::endl;
}


SPECTRIUM_NAMESPACE_END