#pragma once

#include <spectrium/color/color.hpp>



SPECTRIUM_NAMESPACE_BEGIN


class ANSIEscapeSequence;


std::string make_escape_sequence(ANSIEscapeSequence* foreground_sequence, ANSIEscapeSequence* background_sequence = nullptr, ANSIColorMode mode = normal) noexcept;
std::string apply_escape_sequence(const std::string& source, ANSIEscapeSequence* foreground_sequence = nullptr, ANSIEscapeSequence* background_sequence = nullptr, ANSIColorMode mode = normal) noexcept;



/**
 * @brief Base class for the ANSI escape code sequences.
 * */
class ANSIEscapeSequence
{
public:
	ANSIEscapeSequence() = default;
	virtual ~ANSIEscapeSequence() = default;


	/**
	 * @returns The string escape sequence.
	 * */
	virtual std::string make_sequence() const noexcept = 0;


	/**
	 * @returns True if this sequence is invalid, false otherwise.
	 * */
	virtual bool is_invalid() const noexcept;


protected:
	friend std::string make_escape_sequence(ANSIEscapeSequence* foreground_sequence, ANSIEscapeSequence* background_sequence, ANSIColorMode mode) noexcept;

	ANSIColorCode16 m_type = fg_special; /**< "fg_special" or "bg_special" */
};




/**
 * @brief 16 pre-defined coloring ANSI escape sequence.
 * */
class ANSI16EscapeSequence : public ANSIEscapeSequence
{
public:

	/**
	 * @param code: The color code as an "ANSIColorCode16" enum.
	 * */
	explicit ANSI16EscapeSequence(ANSIColorCode16 code = fg_default);

	std::string make_sequence() const noexcept override;

	ANSIColorCode16 code;
};




class ANSI256EscapeSequence : public ANSIEscapeSequence
{
public:
	/**
	 * @param code: The code of any 8-bit value (0-255)
	 * */
	explicit ANSI256EscapeSequence(int code = -1);

	std::string make_sequence() const noexcept override;
	bool is_invalid() const noexcept override;

	int code;
};




class ANSIRGBEscapeSequence : public ANSIEscapeSequence
{
public:
	explicit ANSIRGBEscapeSequence(const RGBColor& rgb);

	std::string make_sequence() const noexcept override;
	bool is_invalid() const noexcept override;

	RGBColor rgb;
};


SPECTRIUM_NAMESPACE_END