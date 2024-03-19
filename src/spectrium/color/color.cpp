#include <spectrium/color/color.hpp>



std::string SPECTRIUM_NAMESPACE paint(const std::string& source, sp::ANSIColorCode16 color, sp::ANSIColorMode mode) noexcept
{
	return GLOBAL_ESC + "[" + std::to_string(mode) + ";" + std::to_string(color) + "m" + source + RESET;
}