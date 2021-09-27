#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "reverse.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Reverse", "ReverseEntireArrayEven");
        int A[]{ 1, 2, 3, 4, 5, 6 };
        int result[]{ 6, 5, 4, 3, 2, 1 };

        which_lib::reverse( std::begin(A), std::end(A) );

        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(result) ) );
    }

    {
        BEGIN_TEST( tm, "Reverse2", "ReverseEntireArrayOdd" );
        int A[]{ 1, 2, 3, 4, 5 };
        int A_E[]{ 5, 4, 3, 2, 1 };

        which_lib::reverse( std::begin(A), std::end(A) );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    {
        BEGIN_TEST( tm,"Reverse3", "ReversePartOfArrayEven");
        int A[]  { 1, 2, 3, 4, 5, 6, 7 };
        int A_E[]{ 1, 2, 6, 5, 4, 3, 7 };

        which_lib::reverse( std::begin(A)+2, std::begin(A)+6 );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    {
        BEGIN_TEST( tm,"Reverse4", "ReversePartOfArrayOdd");
        int A[]{ 1, 2, 3, 4, 5, 6, 7 };
        int A_E[]{ 1, 6, 5, 4, 3, 2, 7 };

        which_lib::reverse( std::begin(A)+1, std::begin(A)+6 );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
