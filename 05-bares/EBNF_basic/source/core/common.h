#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>  // cout, cin
#include <iterator>  // std::distance()
#include <vector>    // std::vector
#include <stack>     // std::stack
#include <sstream>   // std::istringstream
#include <cstddef>   // std::ptrdiff_t
#include <limits>    // std::numeric_limits, para validar a faixa de um inteiro.
#include <algorithm> // std::copy, para copiar substrings.
#include <cctype>    // std::isspace()
#include <iomanip>   //
#include <math.h>    // pow

// Aliases
    /**
     * @brief This enum is used to determine the types of executions error.
     * 
     */
    enum execution_error {
        OK = 0, //!< Expression successfuly parsed.
        NUMERIC_OVERFLOW,
        DIVISION_BY_ZERO,
    };
    typedef short int required_int_type; //!< The interger type we accept as valid for an expression.
    typedef long long int input_int_type; //!< The integer type that we read from the input, which should be larger than  he required integer range (so we can identify input errors).

#endif