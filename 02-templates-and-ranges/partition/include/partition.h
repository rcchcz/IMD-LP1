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
 * This function reorders the interval [first, last) so that all elements that satisfy a certain predicate p
 * come before elements that do not satisfy that same predicate p.
 *
 * @tparam ForwardIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param p Function that returns true when a given condition is satisfied or false otherwise.
 *
 * @return Iterator pointing to the element rifht after the last element in the reordered range that satisfies
 *             the predicate p.
 * 
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    ForwardIt slow = first;
    ForwardIt fast = first;
    // while-loop iterates over the entire range
    while(fast != last) {
            // test if fast satisfies p
            if(p(*fast)) {
                // fast sastisfaz p, troque slow e fast
                // in short, pulls the element in fast to the subrange that satisfies p
                std::swap(*slow, *fast);
                slow++;
            }
            fast++;
        }
    // logical end of the subrange of elements that satisfy p
    return slow;
}

}
#endif
