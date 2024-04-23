#include <spectrium/color/escape_sequence.hpp>

#include <sstream>



bool SPECTRIUM_NAMESPACE ANSIEscapeSequence::is_invalid() const noexcept
{
	return false;
}





std::string SPECTRIUM_NAMESPACE make_escape_sequence(ANSIEscapeSequence* const foreground_sequence, ANSIEscapeSequence* const background_sequence, const ANSIColorMode mode) noexcept
{
	const bool valid_foreground = foreground_sequence && !foreground_sequence->is_invalid();
	const bool valid_background = background_sequence && !background_sequence->is_invalid();

	if (valid_foreground)
		foreground_sequence->m_type = fg_special;

	if (valid_background)
		background_sequence->m_type = bg_special;


	std::stringstream sequence;


	sequence << GLOBAL_ESCC;
	sequence << mode;

	if (valid_foreground)
		sequence << ';' << foreground_sequence->make_sequence();

	if (valid_background)
		sequence << ';' << background_sequence->make_sequence();

	sequence << 'm';

	return sequence.str();
}


std::string SPECTRIUM_NAMESPACE apply_escape_sequence(const std::string& source, sp::ANSIEscapeSequence* foreground_sequence, sp::ANSIEscapeSequence* background_sequence, sp::ANSIColorMode mode) noexcept
{
	return make_escape_sequence(foreground_sequence, background_sequence, mode) + source + RESET;
}





SPECTRIUM_NAMESPACE ANSI16EscapeSequence::ANSI16EscapeSequence(sp::ANSIColorCode16 code)
{
	this->code = code;
}


std::string SPECTRIUM_NAMESPACE ANSI16EscapeSequence::make_sequence() const noexcept
{
	return std::to_string(code);
}





SPECTRIUM_NAMESPACE ANSI256EscapeSequence::ANSI256EscapeSequence(int code)
{
	this->code = code;
}


std::string SPECTRIUM_NAMESPACE ANSI256EscapeSequence::make_sequence() const noexcept
{
	if (is_invalid())
		return {};

	std::stringstream sequence;

	sequence << ((m_type == fg_special) ? 38 : 48) << ';';
	sequence << SPECIAL_8BITCLR << ';';
	sequence << code;

	return sequence.str();
}


bool SPECTRIUM_NAMESPACE ANSI256EscapeSequence::is_invalid() const noexcept
{
	return code < 0;
}





SPECTRIUM_NAMESPACE ANSIRGBEscapeSequence::ANSIRGBEscapeSequence(const RGBColor& rgb)
{
	this->rgb = rgb;
}


std::string SPECTRIUM_NAMESPACE ANSIRGBEscapeSequence::make_sequence() const noexcept
{
	if (is_invalid())
		return {};

	std::stringstream sequence;

	sequence << ((m_type == fg_special) ? 38 : 48) << ';';
	sequence << SPECIAL_RGBCLR << ';';
	sequence << rgb.red << ';' << rgb.green << ';' << rgb.blue;

	return sequence.str();
}


bool SPECTRIUM_NAMESPACE ANSIRGBEscapeSequence::is_invalid() const noexcept
{
	return (rgb.red < 0 || rgb.green < 0 || rgb.blue < 0);
}