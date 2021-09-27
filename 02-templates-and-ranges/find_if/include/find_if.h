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
 * This function looks for the first occurrence in the range [first, last) of an element for which a given
 * predicate is true. If the predicate is false on all elements, the function returns last.
 *
 * @tparam InputIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param p Function to test if a value in the range satisfies predicate p.
 *
 * @return The iterator to the first element in the range that satisfies a certain predicate, or last. 
 * 
 */
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    // while-loop to find the first occurrence of an element that satisfies p
    // linear search
    while(first != last) {
        // if true, end search and return value
        if(p(*first)) return first;
        // if false, check the next element
        first++;
    }
    // p is false for all elements, return last
    return last;
}

}
#endif
