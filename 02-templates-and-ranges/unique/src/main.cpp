#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "unique.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Unique", "SomeRepetitions");
        int A[]{ 1, 2, 3, 4, 5, 5, 4, 4, 4, 3, 2, 3, 2, 1 };
        int A_E[]{ 1, 2, 3, 4, 5 };

        auto result = which_lib::unique( std::begin(A), std::end(A), std::equal_to<int>() );
                // []( const int& a, const int& b )->bool{ return a == b; } );

        EXPECT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
    }

    {
        BEGIN_TEST( tm,"Unique2" , "AllEquals");
        int A[]{ 1, 1, 1, 1, 1, 1, 1 };
        int A_E[]{ 1 };

        auto result = which_lib::unique( std::begin(A), std::end(A),
                []( const int& a, const int& b )->bool{ return a == b; } );

        EXPECT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
    }

    {
        BEGIN_TEST( tm,"Unique3", "AllAreUnique");
        int A[]{ 1, 2, 3, 4, 5, 6, 7 };
        int A_E[]{ 1, 2, 3, 4, 5, 6, 7 };

        auto result = which_lib::unique( std::begin(A), std::end(A),
                []( const int& a, const int& b )->bool{ return a == b; } );

        EXPECT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
    }

    {
        BEGIN_TEST( tm,"Unique4", "MirrorUnique");
        int A[]{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
        int A_E[]{ 1, 2, 3, 4, 5 };

        auto result = which_lib::unique( std::begin(A), std::end(A),
                []( const int& a, const int& b )->bool{ return a == b; } );

        EXPECT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
