#pragma once

#include <string>

#include <spectrium/macro.hpp>
#include <spectrium/color/escape.hpp>



SPECTRIUM_NAMESPACE_BEGIN


//std::string escape_syntax() noexcept;


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



const std::string RESET = GLOBAL_ESC + "[" + "0m"; /**< Resets text color and mode. */



/**
 * @brief Paints a string with a color and mode.
 *
 * @param source: The string source.
 * @param color: The color to paint.
 * @param mode: The mode of the text.
 *
 * @returns A string with the selected color and mode.
 * */
std::string paint(const std::string& source, ANSIColorCode16 color, ANSIColorMode mode = normal) noexcept;


SPECTRIUM_NAMESPACE_END