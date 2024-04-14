#pragma once

#include <cstdint>

#include <string>
#include <initializer_list>

#include <spectrium/macro.hpp>
#include <spectrium/color/escape.hpp>



SPECTRIUM_NAMESPACE_BEGIN


enum ANSIColorCode16
{
	reset = 0,

	// foreground ------- background

	fg_black   = 30,   bg_black   = 40,
	fg_red     = 31,   bg_red     = 41,
	fg_green   = 32,   bg_green   = 42,
	fg_yellow  = 33,   bg_yellow  = 43,
	fg_blue    = 34,   bg_blue    = 44,
	fg_magenta = 35,   bg_magenta = 45,
	fg_cyan    = 36,   bg_cyan    = 46,
	fg_white   = 37,   bg_white   = 47,
	fg_special = 38,   bg_special = 48,
	fg_default = 39,   bg_default = 49,
};


enum ANSIColorMode
{
	normal = 0,
	bold,
	dim,
	italic,
	underline,
	blink,
	reverse = 7,
	hidden,
	strikethrough
};



const std::string RESET = GLOBAL_ESCC + "0m"; /**< Resets text color and mode. */




/**
 * @brief Creates a ANSI escape code with specific control codes.
 *
 * i.e. If the input is "clr({ 0, 31, 43 });", the output would be "ESC[0;31;43m"
 *
 * @param codes: The codes to put into the escape sequence.
 *
 * @returns A string ANSI escape code with the codes.
 * */
std::string clr(const std::initializer_list<int>& codes) noexcept;
std::string clr(const std::string& source, const std::initializer_list<int>& codes) noexcept;

/**
 * @brief Uses 16 pre-defined ANSI colors.
 *
 * @param source: The string source to be painted.
 * @param fg_color: The foreground color.
 *
 * There are also other overloads that accepts background colors and exhibition mode.
 * */
std::string clr(const std::string& source, ANSIColorCode16 fg_color) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorMode mode) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color, ANSIColorMode mode) noexcept;



SPECTRIUM_NAMESPACE_END