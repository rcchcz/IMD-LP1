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
 * This function removes repetitions of elements within a range [first, last), making each element unique.
 *
 * @tparam InputIt Iterator for the range.
 * @tparam Equal Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param eq Function that returns true when the two arguments are equal, or false otherwise.
 *
 * @return the iterator to the logical end after processing.
 * 
 */
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
    InputIt slow = first;
    InputIt fast = first;
    // while-loop iterates over the entire range
    while(first != last) {
        // while-loop iterates over the entire sub-range right after first
        while(fast != last) {
            // use eq to compare, negation to get only unequal elements
            if(!eq(*first, *slow)) {
                *slow = *fast;
                slow++;
            }
            fast++;
        }
        first++;
    }
    // logical end after data processing
    return slow;
}

}
#endif
