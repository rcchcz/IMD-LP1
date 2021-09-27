/*! 
 * Receives 5 integer values ​​from standard input, counts how many of
 * these values ​​are negative, and prints this information to standard
 * output.
 *
 * @param num Integer entered by the user.
 */

#include <iostream>
using std::cin;
using std::cout;

const int SIZE = 5; // store input size in case of future changes

int main(void)
{
    int num = 0; // store the user input
    int neg = 0; // store the negative numbers amount

    // get user input and count negative numbers
    for(int count = 0; count < SIZE; count++) {
        std::cin >> num;
        if (num < 0) neg++;
    }

    std::cout << neg;

    return 0;
}