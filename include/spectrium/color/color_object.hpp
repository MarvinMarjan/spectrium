#pragma once

#include <spectrium/color/color.hpp>



SPECTRIUM_NAMESPACE_BEGIN


template <typename T>
struct ColorStruct
{
	T foreground;
	T background;
	ANSIColorMode mode = normal;
};




template <>
struct ColorStruct<ANSIColorCode16>
{
	ANSIColorCode16 foreground = fg_default;
	ANSIColorCode16 background = bg_default;
	ANSIColorMode mode = normal;
};


template <>
struct ColorStruct<std::int16_t>
{
	std::int16_t foreground = -1;
	std::int16_t background = -1;
	ANSIColorMode mode = normal;
};


SPECTRIUM_NAMESPACE_END