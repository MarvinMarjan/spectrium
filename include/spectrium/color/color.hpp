#pragma once

#include <cstdint>

#include <string>
#include <initializer_list>

#include <spectrium/color/escape_introducer.hpp>



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


const int SPECIAL_8BITCLR = 5;
const int SPECIAL_RGBCLR = 2;


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



struct RGBColor
{
	int red = 255;
	int green = 255;
	int blue = 255;
};



template <typename T>
struct ColorStruct;


using ColorStruct16 = ColorStruct<ANSIColorCode16>;
using ColorStruct256 = ColorStruct<int>;
using ColorStructRGB = ColorStruct<RGBColor>;



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
 * There are also other overloads that accepts background colors, exhibition mode and others that only returns the
 * created escape sequence.
 * */
std::string clr(const std::string& source, ANSIColorCode16 fg_color) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorMode mode) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color) noexcept;
std::string clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color, ANSIColorMode mode) noexcept;

std::string clr(ANSIColorCode16 fg_color) noexcept;
std::string clr(ANSIColorCode16 fg_color, ANSIColorMode mode) noexcept;
std::string clr(ANSIColorCode16 fg_color, ANSIColorCode16 bg_color) noexcept;
std::string clr(ANSIColorCode16 fg_color, ANSIColorCode16 bg_color, ANSIColorMode mode) noexcept;




/**
 * @brief Uses 8-bit (0-256) ANSI colors.
 *
 * @param source: The string source to be painted.
 * @param fg_color: The foreground color.
 *
 * There are also other overloads that accepts background colors, exhibition mode and others that only returns the
 * created escape sequence.
 *
 * A table with the 256 colors and its visual representation can be found at
 * https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#256-colors
 * */
std::string clr(const std::string& source, int fg_color) noexcept;
std::string clr(const std::string& source, int fg_color, ANSIColorMode mode) noexcept;
std::string clr(const std::string& source, int fg_color, int bg_color) noexcept;
std::string clr(const std::string& source, int fg_color, int bg_color, ANSIColorMode mode) noexcept;

std::string clr(int fg_color) noexcept;
std::string clr(int fg_color, ANSIColorMode mode) noexcept;
std::string clr(int fg_color, int bg_color) noexcept;
std::string clr(int fg_color, int bg_color, ANSIColorMode mode) noexcept;




std::string clr(const std::string& source, const RGBColor& fg_color) noexcept;
std::string clr(const std::string& source, const RGBColor& fg_color, ANSIColorMode mode) noexcept;
std::string clr(const std::string& source, const RGBColor& fg_color, const RGBColor& bg_color) noexcept;
std::string clr(const std::string& source, const RGBColor& fg_color, const RGBColor& bg_color, ANSIColorMode mode) noexcept;

std::string clr(const RGBColor& fg_color) noexcept;
std::string clr(const RGBColor& fg_color, ANSIColorMode mode) noexcept;
std::string clr(const RGBColor& fg_color, const RGBColor& bg_color) noexcept;
std::string clr(const RGBColor& fg_color, const RGBColor& bg_color, ANSIColorMode mode) noexcept;




std::string clr(const std::string& source, const ColorStruct16& color) noexcept;
std::string clr(const ColorStruct16& color) noexcept;




std::string clr(const std::string& source, const ColorStruct256& color) noexcept;
std::string clr(const ColorStruct256& color) noexcept;




std::string clr(const std::string& source, const ColorStructRGB& color) noexcept;
std::string clr(const ColorStructRGB& color) noexcept;


SPECTRIUM_NAMESPACE_END