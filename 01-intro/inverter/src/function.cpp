/*! 
 * Reverse de order of elements inside the array.
 * @param arr Reference to the array with the values.
 */

#include "function.h"
#include <iterator>
using std::iter_swap;

template <size_t SIZE>
void reverse( std::array< std::string, SIZE > & arr )
{
    int stopIndex = arr.size()/2;     // it works because it's a int div
    int initialIndex = 0;             // element at the beginning to be moved to the end 
    int finalIndex = arr.size() - 1;  // element at the end to be moved to the beginning

    // the inversion only goes until stopIndex, it works like a mirror
    for(initialIndex; initialIndex < stopIndex; initialIndex++) {
        std::swap(arr[initialIndex], arr[finalIndex]);
        finalIndex--;
    }

    return;
}