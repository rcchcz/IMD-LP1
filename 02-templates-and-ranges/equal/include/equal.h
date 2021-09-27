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
 * This function checks if all elements in the range [first1, last1) are equal to the elements in the range 
 * [first2, first2+(last1-first1)).
 *
 * @tparam InputIt Iterator for the range.
 * @tparam Equal Function type bool(const T &a, const T &b).
 *
 * @param first1 Pointer to the first element of the first range.
 * @param last1 Pointer to the position right after the last element of the first range.
 * @param first2 Pointer to the first element of the second range.
 * @param eq Function that returns true when the two arguments are equal, or false otherwise.
 *
 * @return True if all elements of the two ranges are equal, false otherwise.
 * 
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
    // check the shortest range, use its logical end to compare ranges
    if(std::distance(first2, first2+(last1-first1)) < std::distance(first1, last1)) last1 = first2 + (last1 - first1);
    // while-loop linearly checks each element of the range
    while(first1 != last1) {
        // use eq to check if the elements are equal
        // return false on first occurrence of inequality between elements
        if(!eq(*first1, *first2)) return false;
        first1++;
        first2++;
    }
    // all elements are equal, return true
    return true;
}

/*! 
 * This function checks if all elements in the range [first1, last1) are equal to the elements in the range 
 * [first2, last2).
 *
 * @tparam InputIt Iterator for the range.
 * @tparam Equal Function type bool(const T &a, const T &b).
 *
 * @param first1 Pointer to the first element of the first range.
 * @param last1 Pointer to the position right after the last element of the first range.
 * @param first2 Pointer to the first element of the second range.
 * @param last2 Pointer to the position right after the last element of the second range.
 * @param eq Function that returns true when the two arguments are equal, or false otherwise.
 *
 * @return True if all elements of the two ranges are equal, false otherwise.
 * 
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
    // return false if ranges have different sizes
    if(std::distance(first2, last2) != std::distance(first1, last1)) return false;
    // if it enters the while-loop, the ranges are the same size, capable of comparison without seg fault
    // while-loop linearly checks each element of the ranges
    while(first1 != last1) {
        // use eq to check if the elements are equal
        // return false on first occurrence of inequality between elements
        if(!eq(*first1, *first2)) return false;
        first1++;
        first2++;
    }
    // all elements are equal, return true
    return true;
}

}
#endif
