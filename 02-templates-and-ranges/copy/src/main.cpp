#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "copy.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Copy" , "CopyEntireArray");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
        int A_E[]{ 'a', 'a', 'a', 'a', 'a', 'a', 'a' };

        which_lib::copy( std::begin(A), std::end(A), std::begin(A_E) );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    {
        BEGIN_TEST( tm,"Copy2", "CopyPartOfArray");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
        int A_E[]{ 'a', 'b', 'a', 'a', 'a', 'a', 'a' };

        which_lib::copy( std::begin(A)+2, std::end(A), std::begin(A_E)+2 );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    {
        BEGIN_TEST( tm,"Copy3", "CopyFinalPartOfArray");
        int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
        int A_E[]{ 'a', 'b', 'c', 'd', 'e', 'b', 'a' };

        which_lib::copy( std::begin(A)+5, std::end(A), std::begin(A_E)+5 );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    {
        BEGIN_TEST( tm,"Copy4", "CopySingleElementArray");
        int A[]{ 'a' };
        int A_E[]{ 'x' };

        which_lib::copy( std::begin(A), std::end(A), std::begin(A_E) );
        EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
    }

    tm.summary();
    std::cout << std::endl;
    return EXIT_SUCCESS;

}
