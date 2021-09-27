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
 * This function takes a range [first, last) and an n_first iterator on this range. It then makes a left 
 * rotation of the elements of this range so that n_first and n_first-1 become, respectively, first and
 * last elements of the range.
 *
 * @tparam ForwardIt Iterator for the range.
 *
 * @param first Pointer to the first element of the range.
 * @param n_first Pointer to the element within the range that is moved to the first position.
 * @param last Pointer to the position right after the last element of the range.
 *
 * @return Iterator to the new position of the first element in the range before rotation.
 * 
 */
template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
    // auxiliary iterator to swap within range
    ForwardIt aux = n_first;
    // while-loop iterates over the range
    while (first != aux)
    {
        // swap and increment
        std::swap (*first++, *aux++);
        // avoid segmentation fault
        if (aux == last) aux = n_first;
        // correction so that the number of necessary changes always happens
        else if (first == n_first) n_first = aux;
    }
    // at the end of the loop, all iterators point to the address of the first element of the initial range
    return aux;
}

}
#endif
