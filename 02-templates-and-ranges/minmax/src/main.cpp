#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "minmax.h"

using namespace graal;


int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        //=== Test #1
        BEGIN_TEST(tm, "MinMax1", "Unique Values Sorted." );
        // DISABLE();
        int A[]{ 1, 2, 3, 4, 5 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;

        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, std::begin(A) );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, std::prev(std::end(A)) );
        EXPECT_EQ( *max, 5 );
    }

    {
        //=== Test #1
        BEGIN_TEST(tm, "MinMax2", "Unique Values Reverse Sorted." );
        // DISABLE();
        int A[]{ 5, 4, 3, 2, 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;

        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, std::prev(std::end(A)) );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, std::begin(A) );
        EXPECT_EQ( *max, 5 );
    }

    {
        BEGIN_TEST(tm, "MinMax3", "All Equal." );
        // DISABLE();
        int A[]{ 1, 1, 1, 1, 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;
        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, std::begin(A) );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, std::prev(std::end(A)) );
        EXPECT_EQ( *max, 1 );
    }

    {
        BEGIN_TEST(tm, "MinMax4", "Unique Values Random Order" );
        int A[]{ 2, 3, 5, 4, 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;
        auto eresult = std::minmax_element( std::begin(A), std::end(A) );
        auto emin = eresult.first;
        auto emax = eresult.second;

        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, emin );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, emax );
        EXPECT_EQ( *max, 5 );
    }

    {
        BEGIN_TEST(tm, "MinMax5", "RepeatedValuesRandomOrder");
        int A[]{ 2, 3, 2, 5, 1, 4, 5, 4, 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;
        auto eresult = std::minmax_element( std::begin(A), std::end(A) );
        auto emin = eresult.first;
        auto emax = eresult.second;
        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, emin );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, emax );
        EXPECT_EQ( *max, 5 );
    }

    {
        BEGIN_TEST( tm,"MinMax6", "EmptyList" );
        int A[]{ 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::begin(A), std::less< int >() );
        //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::begin(A) );
        auto result = graal::minmax( std::begin(A), std::begin(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;
        auto eresult = std::minmax_element( std::begin(A), std::begin(A) );
        auto emin = eresult.first;
        auto emax = eresult.second;

        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, emin );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, emax );
        EXPECT_EQ( *max, 1 );
    }

    {
        BEGIN_TEST( tm, "MinMax7", "SingleElement ");
        int A[]{ 1 };

        //const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
        auto result = graal::minmax( std::begin(A), std::end(A), std::less< int >() );
        auto min = result.first;
        auto max = result.second;
        auto eresult = std::minmax_element( std::begin(A), std::end(A) );
        auto emin = eresult.first;
        auto emax = eresult.second;

        EXPECT_NE( min, nullptr );
        EXPECT_EQ( min, emin );
        EXPECT_EQ( *min, 1 );

        EXPECT_NE( max, nullptr );
        EXPECT_EQ( max, emax );
        EXPECT_EQ( *max, 1 );
    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
