#include <spectrium/color/color.hpp>

#include <spectrium/color/escape_sequence.hpp>
#include <spectrium/color/color_object.hpp>



std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorMode mode) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	ANSI16EscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color, const ANSIColorMode mode) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	ANSI16EscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg, mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	return make_escape_sequence(&fg);
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorMode mode) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	return make_escape_sequence(&fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	ANSI16EscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color, const ANSIColorMode mode) noexcept
{
	ANSI16EscapeSequence fg(fg_color);
	ANSI16EscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg, mode);
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const int fg_color) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const int fg_color, const ANSIColorMode mode) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const int fg_color, const int bg_color) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	ANSI256EscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const int fg_color, const int bg_color, const ANSIColorMode mode) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	ANSI256EscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg, mode);
}




std::string SPECTRIUM_NAMESPACE clr(const int fg_color) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	return make_escape_sequence(&fg);
}


std::string SPECTRIUM_NAMESPACE clr(const int fg_color, const ANSIColorMode mode) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	return make_escape_sequence(&fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const int fg_color, const int bg_color) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	ANSI256EscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const int fg_color, const int bg_color, const ANSIColorMode mode) noexcept
{
	ANSI256EscapeSequence fg(fg_color);
	ANSI256EscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg, mode);
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const RGBColor& fg_color) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const RGBColor& fg_color, const ANSIColorMode mode) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	return apply_escape_sequence(source, &fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const RGBColor& fg_color, const RGBColor& bg_color) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	ANSIRGBEscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const RGBColor& fg_color, const RGBColor& bg_color, const ANSIColorMode mode) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	ANSIRGBEscapeSequence bg(bg_color);
	return apply_escape_sequence(source, &fg, &bg, mode);
}




std::string SPECTRIUM_NAMESPACE clr(const RGBColor& fg_color) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	return make_escape_sequence(&fg);
}


std::string SPECTRIUM_NAMESPACE clr(const RGBColor& fg_color, const ANSIColorMode mode) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	return make_escape_sequence(&fg, nullptr, mode);
}


std::string SPECTRIUM_NAMESPACE clr(const RGBColor& fg_color, const RGBColor& bg_color) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	ANSIRGBEscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg);
}


std::string SPECTRIUM_NAMESPACE clr(const RGBColor& fg_color, const RGBColor& bg_color, const ANSIColorMode mode) noexcept
{
	ANSIRGBEscapeSequence fg(fg_color);
	ANSIRGBEscapeSequence bg(bg_color);
	return make_escape_sequence(&fg, &bg, mode);
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ColorStruct16& color) noexcept
{
	ANSI16EscapeSequence fg(color.foreground);
	ANSI16EscapeSequence bg(color.background);
	return apply_escape_sequence(source, &fg, &bg, color.mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ColorStruct16& color) noexcept
{
	ANSI16EscapeSequence fg(color.foreground);
	ANSI16EscapeSequence bg(color.background);
	return make_escape_sequence(&fg, &bg, color.mode);
}







std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ColorStruct256& color) noexcept
{
	ANSI256EscapeSequence fg(color.foreground);
	ANSI256EscapeSequence bg(color.background);
	return apply_escape_sequence(source, &fg, &bg, color.mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ColorStruct256& color) noexcept
{
	ANSI256EscapeSequence fg(color.foreground);
	ANSI256EscapeSequence bg(color.background);
	return make_escape_sequence(&fg, &bg, color.mode);
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ColorStructRGB& color) noexcept
{
	ANSIRGBEscapeSequence fg(color.foreground);
	ANSIRGBEscapeSequence bg(color.background);
	return apply_escape_sequence(source, &fg, &bg, color.mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ColorStructRGB& color) noexcept
{
	ANSIRGBEscapeSequence fg(color.foreground);
	ANSIRGBEscapeSequence bg(color.background);
	return make_escape_sequence(&fg, &bg, color.mode);
}