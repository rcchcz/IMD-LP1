#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "partition.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Partition", "AllAreTrue");
        int A[]{ 6, 7, 8, 9, 10 };
        int A_E[]{ 6, 7, 8, 9, 10 };

        auto predicate = []( const int& e )->bool{ return e > 5; };

        auto result = which_lib::partition( std::begin(A), std::end(A), predicate );

        // Location of the pointer must be correct.
        EXPECT_EQ( result , std::end(A) );
        // Uset STL function to test whether the partion worked.
        EXPECT_TRUE( std::is_partitioned( std::begin(A), std::end(A), predicate ) );
        // Let us see if the elements have been preserved.
        std::sort(std::begin(A), std::end(A));
        std::vector<int> v_intersection;
        std::set_intersection( std::begin(A), std::end(A),
                std::begin(A_E), std::end(A_E),
                std::back_inserter(v_intersection));
        EXPECT_EQ( std::distance(std::begin(A), std::end(A) ), (long int)v_intersection.size() );
    }

    {
        BEGIN_TEST( tm,"Partition2", "NoneAreTrue");
        int A[]{ 0, 1, 2, 3, 4 };
        int A_E[]{ 0, 1, 2, 3, 4 };

        auto predicate = []( const int& e )->bool{ return e > 5; };

        auto result = which_lib::partition( std::begin(A), std::end(A), predicate );

        // Location of the pointer must be correct.
        EXPECT_EQ( std::distance( std::begin(A), result ), 0 );
        // Uset STL function to test whether the partion worked.
        EXPECT_TRUE( std::is_partitioned( std::begin(A), std::end(A), predicate ) );
        EXPECT_EQ( result, std::begin(A) );
        // Let us see if the elements have been preserved.
        std::sort(std::begin(A), std::end(A));
        std::vector<int> v_intersection;
        std::set_intersection( std::begin(A), std::end(A),
                std::begin(A_E), std::end(A_E),
                std::back_inserter(v_intersection));
        EXPECT_EQ( std::distance(std::begin(A), std::end(A) ), (long int)v_intersection.size() );
    }

    {
        BEGIN_TEST( tm,"Partition3", "SomeAreTrueInverted");
        int A[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int A_E[]{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
        // Lambda
        auto predicate = []( const int& e )->bool{ return e > 5; };

        auto result = which_lib::partition( std::begin(A), std::end(A), predicate );
        EXPECT_EQ( std::distance( std::begin(A), result ), 5 );
        // Uset STL function to test whether the partion worked.
        EXPECT_TRUE( std::is_partitioned( std::begin(A), std::end(A), predicate ) );
        // Let us see if the elements have been preserved.
        std::sort(std::begin(A), std::end(A));
        std::sort(std::begin(A_E), std::end(A_E));
        std::vector<int> v_intersection;
        std::set_intersection( std::begin(A), std::end(A),
                std::begin(A_E), std::end(A_E),
                std::back_inserter(v_intersection));
        EXPECT_EQ( std::distance(std::begin(A), std::end(A) ), (long int)v_intersection.size() );
    }

    {
        BEGIN_TEST( tm,"Partition4", "SomeAreTrueInterleaved");
        int A[]{ 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };
        int A_E[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        auto predicate = []( const int& e )->bool{ return e > 5; };

        auto result = which_lib::partition( std::begin(A), std::end(A), predicate );
        EXPECT_EQ( std::distance( std::begin(A), result ), 5 );
        // Uset STL function to test whether the partion worked.
        EXPECT_TRUE( std::is_partitioned( std::begin(A), std::end(A), predicate ) );
        // Let us see if the elements have been preserved.
        std::sort(std::begin(A), std::end(A));
        std::vector<int> v_intersection;
        std::set_intersection( std::begin(A), std::end(A),
                std::begin(A_E), std::end(A_E),
                std::back_inserter(v_intersection));
        EXPECT_EQ( std::distance(std::begin(A), std::end(A) ), (long int)v_intersection.size() );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
