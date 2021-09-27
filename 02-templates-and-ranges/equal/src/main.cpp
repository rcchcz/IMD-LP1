#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "equal.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    //=== equal, version #1
    {
        BEGIN_TEST( tm,"Equal" , "AllAreEqualSameSize ");
        int A[]{ 'a', 'b', 'c', 'd' };
        int A_E[]{ 'a', 'b', 'c', 'd' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E),
                []( int a, int b )->bool { return a==b; } );
        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"Equal2", "AllAreNotEqualSameSize");
        int A[]{ 'a', 'b', 'c', 'd' };
        int A_E[]{ 'x', 'y', 'z', 'w' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E),
                []( int a, int b )->bool { return a==b; } );
        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"Equal3", "PartAreEqualSameSize");
        int A[]{ 'a', 'b', 'c', 'd' };
        int A_E[]{ 'x', 'y', 'c', 'd' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E),
                []( int a, int b )->bool { return a==b; } );
        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"Equal4", "AllAreEqual1stGreater2nd");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
        int A_E[]{ 'a', 'b', 'c', 'd' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E), std::end(A_E),
                []( int a, int b )->bool { return a==b; } );
	std::cout << "result = " << std::boolalpha << result << '\n';
        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"Equal5", "AllAreEqual1stGreater2ndCorrectRange");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
        int A_E[]{ 'a', 'b', 'c', 'd' };

        bool result;
        result = which_lib::equal( std::begin(A), std::begin(A)+std::distance(std::begin(A_E), std::end(A_E) ),
                std::begin(A_E), std::end(A_E),
                []( int a, int b )->bool { return a==b; } );
        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"Equal6", "PartIsNotEqual");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
        int A_E[]{ 'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E)+2, std::end(A_E)+6,
                []( int a, int b )->bool { return a==b; } );
        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"Equal7", "PartIsEqual");
        int A[]{ 'a', 'b', 'c', 'd'  };
        int A_E[]{ 'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i' };

        bool result;
        result = which_lib::equal( std::begin(A), std::end(A),
                std::begin(A_E)+2, std::begin(A_E)+6,
                []( int a, int b )->bool { return a==b; } );
        EXPECT_TRUE( result );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
