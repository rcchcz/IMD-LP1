#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * This function copies the values ​​from the range [first, last) to a new range starting at d_first.
 *
 * @tparam InputIt Iterator for the range.
 *
 * @param first Pointer to the first element of the range [first, last).
 * @param last Pointer to the position right after the last element of the range [first, last).
 * @param d_first Pointer to the first element of the copy range.
 *
 * @return The iterator that points to the logical end of the copy range.
 *
 */
template<class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first)
{
    // while-loop to copy 
    while(first != last) {
        *d_first = *first;
        d_first++;
        first++;
    }
    // logical end
    return ++d_first;
}

}
#endif
