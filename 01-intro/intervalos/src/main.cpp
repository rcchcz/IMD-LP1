/*! 
 * Reads an unknown number of integer values ​​separated by whitespace
 * and counts how many of them are in each of the intervals [0; 25),
 * [25; 50), [50; 75), [75; 100) and outside these ranges.
 *
 * @param x Integer value.
 * @return The percentage of integer values ​​received for each of the
 *     four ranges and out of them, respectively, one per line.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setprecision;

int main(void)
{
    int SIZE = 5;
    int count[5]{0, 0, 0, 0, 0};
    // count[0] = [0, 25)
    // count[1] = [25, 50)
    // count[2] = [50, 75)
    // count[3] = [75, 100)
    // count[4] = out
    int x = 0;
    int total = 0;

    while(cin >> std::ws >> x) {
        total++;
        // separating values ​​into intervals
        if(x >= 0 && x < 25) count[0]++;
        else if(x >= 25 && x < 50) count[1]++;
        else if(x >= 50 && x < 75) count[2]++;
        else if(x >= 75 && x < 100) count[3]++;
        else if(x < 0 || x >= 100) count[4]++; // could it be only an else statement, but let's play safe
    }

    // quantifying and printing the percentages
    for(int index = 0; index < SIZE; index++) {
        std::cout << std::setprecision(4) << ((float)count[index]/(float)total)*100 << std::endl;
    }
    
    return 0;
}