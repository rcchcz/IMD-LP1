/*! 
 * Finds and returns a pair with the first instance of the smallest element
 * and the last instance of the largest element in an array.
 *
 * @param V This is the array-to-pointer decay representing an array.
 * @param n The array's size.
 *
 * @return A pair of indexes to the first smallest and last largest values.
 */

#include "function.h"

std::pair<int,int> min_max( int V[], size_t n )
{
    if(n == 0) return std::make_pair(-1, -1); // empty array

    int minValue = V[0]; // first occurrence of the smallest value
    std::size_t minIndex = 0;

    int maxValue = V[0]; // last occurrence of largest value
    std::size_t maxIndex = 0;

    for(std::size_t index = 0; index < n; index++) {
        if(V[index] < minValue) {  // first occurrence of the smallest value -- '<' keeps the index
            minValue = V[index];
            minIndex = index;
        }
        
        if(V[index] >= maxValue) { // last occurrence of largest value -- '>=' updates the index
            maxValue = V[index];
            maxIndex = index;
        } 
    }
    
    return std::make_pair(minIndex, maxIndex); 
}