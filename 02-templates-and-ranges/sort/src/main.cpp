#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "sort.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Sort", "BasicUniqueElements");
        int A[]{ 2, 5, 3, 6, 1, 30, 10 };
        int A_O[]{ 1, 2, 3, 5, 6, 10, 30 };

        which_lib::sort( std::begin(A), std::end(A),
                [](const int&a, const int& b){ return a<b; } );

        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
    }

    {
        BEGIN_TEST( tm,"Sort2",  "BasicDuplicateElements");
        int A[]{ 7, 6, 5, 4, 1, 1, 1 };
        int A_O[]{ 1, 1, 1, 4, 5, 6, 7 };

        which_lib::sort( std::begin(A), std::end(A),
                [](const int&a, const int& b){ return a<b; } );

        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
    }

    {
        BEGIN_TEST( tm,"Sort3", "AlreadySorted");
        int A[]{ 1, 2, 3, 4, 5, 6, 7 };
        int A_O[]{ 1, 2, 3, 4, 5, 6, 7 };

        which_lib::sort( std::begin(A), std::end(A),
                [](const int&a, const int& b){ return a<b; } );

        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
    }

    {
        BEGIN_TEST( tm,"Sort4", "ReverseSorted");
        int A[]{ 7, 6, 5, 4, 3, 2, 1 };
        int A_O[]{ 1, 2, 3, 4, 5, 6, 7 };

        which_lib::sort( std::begin(A), std::end(A),
                [](const int&a, const int& b){ return a<b; } );

        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
    }

    
    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
