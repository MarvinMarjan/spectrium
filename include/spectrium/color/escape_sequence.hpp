#pragma once

#include <spectrium/color/color.hpp>



SPECTRIUM_NAMESPACE_BEGIN


class ANSIEscapeSequence;


std::string make_escape_sequence(ANSIEscapeSequence* foreground_sequence, ANSIEscapeSequence* background_sequence = nullptr, ANSIColorMode mode = normal) noexcept;
std::string apply_escape_sequence(const std::string& source, ANSIEscapeSequence* foreground_sequence = nullptr, ANSIEscapeSequence* background_sequence = nullptr, ANSIColorMode mode = normal) noexcept;



class ANSIEscapeSequence
{
public:
	ANSIEscapeSequence() = default;
	virtual ~ANSIEscapeSequence() = default;


	virtual std::string make_sequence() const noexcept = 0;
	virtual bool is_invalid() const noexcept;


protected:
	friend std::string make_escape_sequence(ANSIEscapeSequence* foreground_sequence, ANSIEscapeSequence* background_sequence, ANSIColorMode mode) noexcept;

	ANSIColorCode16 m_type = fg_special;
};




class ANSI16EscapeSequence : public ANSIEscapeSequence
{
public:
	explicit ANSI16EscapeSequence(ANSIColorCode16 code = fg_default);

	std::string make_sequence() const noexcept override;

	ANSIColorCode16 code;
};




class ANSI256EscapeSequence : public ANSIEscapeSequence
{
public:
	explicit ANSI256EscapeSequence(int code = -1);

	std::string make_sequence() const noexcept override;
	bool is_invalid() const noexcept override;

	int code;
};


SPECTRIUM_NAMESPACE_END