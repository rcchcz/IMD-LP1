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
 * This function sorts the elements within a range [first, last).
 *
 * @tparam ForwardIt Iterator for the range.
 * @tparam ForwardIt Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param cmp Function that returns true when the first argument is less than the second, false otherwise.
 *
 * 
 */
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
    ForwardIt current = first;
    // while-loop over range [first, last)
    while(first != last) {
        // setting current = first to iterate over the range [current, last)
        current = first;
        while(current != last) {
            // return true whenever an element in [current, last) is less than first
            if(cmp(*current, *first)) {
                // pull the smaller element to the beginning and push the larger element to the end
                std::swap(*current, *first);
            }
            current++;
        }
        first++;
    }
}

}
#endif
