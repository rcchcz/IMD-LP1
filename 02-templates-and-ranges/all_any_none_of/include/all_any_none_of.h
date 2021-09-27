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
 * This function checks if predicate p is true for all elements in the range [first, last).
 *
 * @tparam InputIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param p Function that returns true when a given condition is satisfied or false otherwise.
 *
 * @return True if all elements of the range satisfy p, false otherwise.
 * 
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    // empty range, return false
    if(first == last) return false;
    // while-loop linearly checking p for each element
    while(first != last) {
        // p is false for current element, return false
        if(!p(*first)) return false;
        first++;
    }
    // p is true for all elements, return true
    return true;
}
 
/*! 
 * This function checks if predicate p is true for at least one element in the range [first, last).
 *
 * @tparam InputIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param p Function that returns true when a given condition is satisfied or false otherwise.
 *
 * @return True if all at least one element of the range satisfy p, false otherwise.
 * 
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    // while-loop linearly checking p for each element
    while(first != last) {
        // p is true for at least one element, return true
        if(p(*first)) return true;
        first++;
    }
    // p is false for all elements, return false
    return false;
}

/*! 
 * This function checks if predicate p is false for all elements in the range [first, last).
 *
 * @tparam InputIt Iterator for the range.
 * @tparam UnaryPredicate Function type bool(const T &a, const T &b).
 *
 * @param first Pointer to the first element of the range.
 * @param last Pointer to the position right after the last element of the range.
 * @param p Function that returns true when a given condition is satisfied or false otherwise.
 *
 * @return True if all elements of the range do not satisfy p, false otherwise.
 * 
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    // while-loop linearly checking p for each element
    while(first != last) {
        // p is true for at least one element, return false
        if(p(*first)) return false;
        first++;
    }
    // p is false for all elements, return true
    return true;
}

}
#endif
