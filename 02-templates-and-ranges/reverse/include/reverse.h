#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
using std::advance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * This function reverses the order of each element in a range [first, last).
 *
 * @tparam BidirIt Iterator for the range.
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 *
 */
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
    // get the middle of the range, it will be a reversal axis
    BidirIt mid = first + (last - first)/2;

    // while-loop to swap the position of elements
    while(first != mid) {
        std::swap(*first, *(--last));
        first++;
    }
}

}
#endif
