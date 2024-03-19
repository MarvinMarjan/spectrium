#pragma once

#include <string>

#include <spectrium/macro.hpp>



SPECTRIUM_NAMESPACE_BEGIN


const std::string OCTAL_ESC = "\033";       /**< Octal ANSI escape. */
const std::string UNICODE_ESC = "\u001b";   /**< Unicode ANSI escape. */
const std::string HEXADECIMAL_ESC = "\x1b"; /**< Hexadecimal escape. */

const std::string GLOBAL_ESC = HEXADECIMAL_ESC; /**< Escape code used by the library. */


SPECTRIUM_NAMESPACE_END