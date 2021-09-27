#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "find.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Find", "NoneIsEqual");
        int A[]{ 'k', 'a', 'b', 'l', 'q' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::end(A), result );
    }

    {
        BEGIN_TEST( tm,"Find2", "AllAreEqual");
        int A[]{ 'x', 'x', 'x', 'x', 'x' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::begin(A), result );
    }

    {
        BEGIN_TEST( tm,"Find3", "SeveralAreEqual");
        int A[]{ 'a', 'x', 'b', 'x', 'c' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::begin(A)+1, result );
    }

    {
        BEGIN_TEST( tm,"Find4", "SingleEqualAtBeginning");
        int A[]{ 'x', 'a', 'q', 'l', 'k' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::begin(A), result );
    }

    {
        BEGIN_TEST( tm,"Find5", "SingleEqualAtEnd" );
        int A[]{ 'k', 'a', 'q', 'l', 'x' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::prev(std::end(A)), result );
    }

    {
        BEGIN_TEST( tm,"Find6", "SingleEqualInMiddle");
        int A[]{ 'k', 'a', 'x', 'l', 'q' };
        int target{ 'x' };
        auto result = graal::find( std::begin(A), std::end(A), target,
                []( int a, int b )->bool{ return a == b; } );
        EXPECT_EQ( std::begin(A)+2, result );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
