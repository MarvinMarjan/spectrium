#include <spectrium/color/color.hpp>

#include <sstream>

#include <spectrium/color/color_object.hpp>



std::string SPECTRIUM_NAMESPACE clr(const std::initializer_list<int>& codes) noexcept
{
	std::stringstream escape_code;

	// begins the escape sequence.
	escape_code << GLOBAL_ESCC;


	for (const int& code : codes)
	{
		// todo: solve this
		if (code == -1)
			continue;

		// adds the code.
		escape_code << std::to_string(code);

		// ';' is not added to the last code of the sequence.
		if (&code != codes.end() - 1)
			escape_code << ';';
	}


	// ends the escape sequence.
	escape_code << 'm';

	return escape_code.str();
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::initializer_list<int>& codes) noexcept
{
	return clr(codes) + source + RESET;
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color) noexcept
{
	return clr(source, { normal, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color) noexcept
{
	return clr(source, { normal, fg_color, bg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color, const ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_color, bg_color });
}




std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color) noexcept
{
	return clr({ normal, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorMode mode) noexcept
{
	return clr({ mode, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color) noexcept
{
	return clr({ normal, fg_color, bg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const ANSIColorCode16 fg_color, const ANSIColorCode16 bg_color, const ANSIColorMode mode) noexcept
{
	return clr({ mode, fg_color, bg_color });
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::int16_t fg_color) noexcept
{
	return clr(source, { normal, fg_special, SPECIAL_8BITCLR, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::int16_t fg_color, const ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_special, SPECIAL_8BITCLR, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::int16_t fg_color, const std::int16_t bg_color) noexcept
{
	return clr(source, { normal, fg_special, SPECIAL_8BITCLR, fg_color, bg_special, SPECIAL_8BITCLR, bg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::int16_t fg_color, const std::int16_t bg_color, const ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_special, SPECIAL_8BITCLR, fg_color, bg_special, SPECIAL_8BITCLR, bg_color });
}




std::string SPECTRIUM_NAMESPACE clr(const std::int16_t fg_color) noexcept
{
	return clr({ normal, fg_special, SPECIAL_8BITCLR, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::int16_t fg_color, const ANSIColorMode mode) noexcept
{
	return clr({ mode, fg_special, SPECIAL_8BITCLR, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::int16_t fg_color, const std::int16_t bg_color) noexcept
{
	return clr({ normal, fg_special, SPECIAL_8BITCLR, fg_color, bg_special, SPECIAL_8BITCLR, bg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::int16_t fg_color, const std::int16_t bg_color, const ANSIColorMode mode) noexcept
{
	return clr({ mode, fg_special, SPECIAL_8BITCLR, fg_color, bg_special, SPECIAL_8BITCLR, bg_color });
}








std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ColorStruct16& color) noexcept
{
	return clr(source, color.foreground, color.background, color.mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ColorStruct16& color) noexcept
{
	return clr(color.foreground, color.background, color.mode);
}







std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const ColorStruct256& color) noexcept
{
	return clr(source, color.foreground, color.background, color.mode);
}




std::string SPECTRIUM_NAMESPACE clr(const ColorStruct256& color) noexcept
{
	return clr(color.foreground, color.background, color.mode);
}