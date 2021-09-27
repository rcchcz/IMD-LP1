/*!
 * Reads an undetermined number of integer value pairs and
 * for each pair calculates and writes the sum of the first
 * n consecutive integers from m (inclusive), if n > 0; or
 * the sum of the n first preceding integers from m (inclusive),
 * if n < 0.
 * 
 * @param m Integer value representing the initial term of the sum.
 * @param n Integer value representing the number of terms to
 *     be added from m and the direction of the sum.
 * @return An integer representing the sum of the terms.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main( void )
{
    // 0 was set as initialization value to avoid undefined behavior
    int m = 0;    // holds the starting number
    int n = 0;    // holds the number of consecutive integers and the counting direction
    int sum = 0;  
    int startingNumber = 0;

    while(std::cin >> m >> n) {
        // resets the variables
        startingNumber = m;
        sum = 0;

        if(n > 0) {    // increasing
            for(int count = 0; count < n; count++) {
                sum += startingNumber;
                startingNumber++;
            }
        } else if(n < 0) { // decreasing
            int absn = n * (-1); // absolute value of n
            for(int count = 0; count < absn; count++) {
                sum += startingNumber;
                startingNumber--;
            }
        } else sum = m; // zero step

        // output
        std::cout << sum << std::endl;
    }

    return 0;
}