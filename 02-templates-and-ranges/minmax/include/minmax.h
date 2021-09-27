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
 * This function looks for the smallest and largest elements in a [first, last) range.
 * If the range is empty, the two return iterators point to first.
 * If there are multiple occurrences of the first element, the iterator will point to its first occurrence.
 * If there are multiple occurrences of the largest element, the iterator will point to its last occurrence.
 *
 * @tparam Itr iterator for the range.
 * @tparam Compare function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param cmp Comparison function that returns true when the first parameter is less than the second.
 *
 * @return std::pair containing smallest and largest element, in this order.
 *
 */
template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{
    Itr min = first;
    Itr max = first;

    // iterating over the range
    while(first != last) {
        // true if first < min, update min
        if(cmp(*first, *min)) min = first;
        // deny the value of cmp, return true if first >= max, update max
        if(!cmp(*first, *max)) max = first;
        first++;
    }
    
    return std::make_pair(min, max);
}

}
#endif
