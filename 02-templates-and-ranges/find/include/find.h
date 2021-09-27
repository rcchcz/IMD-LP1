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
 * This function looks for the first occurrence in the range [first, last) of an element equal to the target
 * value. If the value is not found in the range, the function returns last.
 *
 * @tparam InputIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param value Target value.
 * @param eq Function to compare each element to the target value.
 *
 * @return The iterator to the first element in the range equal to the target value, or last.
 * 
 */
template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{
    // while-loop to linearly search for the first element equal to the target value
    while(first != last) {
        // use eq to compare one at a time
        // target value found, return
        if(eq(value, *first)) return first;
        // target value not found, check next
        first++;
    }
    // target value not found within range, return last
    return last;
}

}
#endif
