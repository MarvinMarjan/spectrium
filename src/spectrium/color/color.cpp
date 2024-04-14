#include <spectrium/color/color.hpp>

#include <sstream>



std::string SPECTRIUM_NAMESPACE clr(const std::initializer_list<int>& codes) noexcept
{
	std::stringstream escape_code;

	escape_code << GLOBAL_ESCC;


	for (const int& code : codes)
	{
		escape_code << std::to_string(code);

		if (&code != codes.end() - 1)
			escape_code << ';';
	}


	escape_code << 'm';

	return escape_code.str();
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, const std::initializer_list<int>& codes) noexcept
{
	return clr(codes) + source + RESET;
}




std::string SPECTRIUM_NAMESPACE clr(const std::string& source, ANSIColorCode16 fg_color) noexcept
{
	return clr(source, { normal, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color) noexcept
{
	return clr(source, { normal, fg_color, bg_color });
}


std::string SPECTRIUM_NAMESPACE clr(const std::string& source, ANSIColorCode16 fg_color, ANSIColorCode16 bg_color, ANSIColorMode mode) noexcept
{
	return clr(source, { mode, fg_color, bg_color });
}