#include <spectrium/color/color.hpp>

#include <spectrium/color/escape_sequence.hpp>
#include <spectrium/color/color_object.hpp>



// If the 8-bit color code is invalid, return an empty string. Otherwise, return the escape sequence.
//static std::string check_ansi256_syntax(const std::initializer_list<int>& codes, std::initializer_list<int>::const_iterator& iterator) noexcept
//{
//	std::stringstream escape_code;
//
//	escape_code << *iterator << ';';           // 38 or 48
//	escape_code << sp::SPECIAL_8BITCLR << ';'; // 5
//
//	// is the 8-bit color code invalid?
//	if (*(iterator += 2) < 0)
//		return {};
//
//	escape_code << *iterator;
//
//	if (iterator + 1 != codes.end())
//		escape_code << ';';
//
//	return escape_code.str();
//}
//
//
//std::string SPECTRIUM_NAMESPACE clr(const std::initializer_list<int>& codes) noexcept
//{
//	std::stringstream escape_code;
//
//	// begins the escape sequence.
//	//escape_code << GLOBAL_ESCC;
//
//
//	for (auto begin = codes.begin(); begin != codes.end(); begin++)
//	{
//		const int code = *begin;
//		auto next_iterator = begin + 1;
//
//
//		if (code < 0)
//			continue;
//
//		const bool is_special = (code == fg_special || code == bg_special);
//		const bool is_8bitclr = (*next_iterator == SPECIAL_8BITCLR);
//
//		// adds the code.
//
//		// is it ANSI 8-bit coloring?
//		// 8-bit coloring needs to have a special treatment with the syntax.
//		if (is_special && is_8bitclr)
//		{
//			escape_code << check_ansi256_syntax(codes, begin);
//			continue;
//		}
//
//		else
//			escape_code << code;
//
//		// ';' is not added to the last code of the sequence.
//		if (begin + 1 != codes.end())
//			escape_code << ';';
//	}
//
//
//	// ends the escape sequence.
//	escape_code << 'm';
//
//	return escape_code.str();
//}
//
//
//std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::initializer_list<int>& codes) noexcept
//{
//	return clr(codes) + source + RESET;
//}








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