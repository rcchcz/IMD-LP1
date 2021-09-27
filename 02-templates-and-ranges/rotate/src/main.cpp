#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "rotate.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Rotate2", "Block");
        int A[]{ 1, 2, 3, 4, 5, 6, 7 };
        int A_E[]{ 5, 6, 7, 1, 2, 3, 4 };

        which_lib::rotate( std::begin(A), std::begin(A)+4, std::end(A) );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );

    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
