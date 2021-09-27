/*! 
 * Remove negative and zero values from an array, preserving the
 * relative order of the original values that will remain in the
 * resulting array.
 * We do not alter the origimal memory associated withe the input
 * array. Rather, we just rearrange the values inside the array
 * and return a pointer to the new 'logical' end of the array,
 * after the processes of eliminating the required elements is
 * finished.
 *
 * @param first Pointer to the beginning of the range we want to filter.
 * @param last Pointer just past the last valid value of the range we want to filter.
 * @return a pointer to the new 'logical' end of the array.
 */

int * filter( int * first, int * last )
{
    int * current = first;   // checks if the current position reached the last element
    while(first != last && current != last) { // loops through the array
        if(*(first) <= 0) { // checks if 'first' points to a less than or equal to zero element
            for(int i = 0; first + i != last; i++) {
                *(first + i) = *(first + i + 1); // overwrites with the adjacent left element
            }
            current++; // increases the current check position by one
            last--; // decrease the logical size by one
        } else first++; // if 'first' points to a valid element, it advances one position
    }
    return last;
}