#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "all_any_none_of.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    //== all_of

    {
        BEGIN_TEST( tm,"AllOf", "AllAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"AllOf2", "AllAreNotOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"AllOf3", "FewAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"AllOf4", "EmptyInput");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::all_of( std::begin(A), std::begin(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result );
    }

    //== any_of

    {
        BEGIN_TEST( tm,"AnyOf", "AllAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"AnyOf1", "AllAreNotOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"AnyOf2", "FewAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"AnyOf3", "EmptyInput");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::any_of( std::begin(A), std::begin(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result );
    }

    //== none_of

    {
        BEGIN_TEST( tm,"NoneOf",  "AllAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"NoneOf2" , "AllAreNotOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_TRUE( result );
    }

    {
        BEGIN_TEST( tm,"NoneOf3", "FewAreOk");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result );
    }

    {
        BEGIN_TEST( tm,"NoneOf4", "EmptyInput");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = which_lib::none_of( std::begin(A), std::begin(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_TRUE( result );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
