#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "find_if.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"FindIf", "SeveralAreTrue");
        int A[]{ 1, 6, 3, 6, 5, 2, 6 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::begin(A)+1, result );
    }

    {
        BEGIN_TEST( tm,"FindIf2", "NoneIsTrue");
        int A[]{ 1, 2, 3, 4, 5 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::end(A), result );
    }

    {
        BEGIN_TEST( tm,"FindIf3", "AllAreTrue");
        int A[]{ 6, 7, 8, 9, 10 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::begin(A), result );
    }

    {
        BEGIN_TEST( tm,"FindIf4", "PredicateTrueAtBeginning");
        int A[]{ 6, 2, 3, 4, 5, 2, 1 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::begin(A), result );
    }

    {
        BEGIN_TEST( tm,"FindIf5", "PredicateTrueAtMiddle");
        int A[]{ 1, 2, 3, 6, 5, 2, 1 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::begin(A)+3, result );
    }

    {
        BEGIN_TEST( tm,"FindIf6", "PredicateTrueAtEnd");
        int A[]{ 1, 2, 3, 4, 5, 2, 6 };
        auto result = which_lib::find_if( std::begin(A), std::end(A),
                []( int e )->bool{ return e > 5 ; } );
        EXPECT_EQ( std::prev(std::end(A)), result );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
