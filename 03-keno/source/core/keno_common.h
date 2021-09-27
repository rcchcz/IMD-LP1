#ifndef _KENO_COMMON_H_
#define _KENO_COMMON_H_

/*!
 *  This is a set of common definition for classes KenoGame and KenoBet.
 *  This is to avoid circular referencing.
 *
 *  @author Selan R. dos Santos
 *  @date April 19th, 2017
 *  @file keno_common.h
 */

#include <fstream>  // For handling files.
#include <sstream>  // For the stringstream.
#include <iostream> // cout, cerr, endl.
#include <vector>   // vector.
#include <string>   // string.
#include <random>   // shuffle and random stuff.
#include <iomanip>  // setw, setfill.
#include <algorithm> //sort.
#include <chrono>   // seed for shuffle.



namespace Keno
{
    using number_type = unsigned short int; //<! data type for a keno hit.
    using cash_type = float; //<! Defines the wage type in this application.
    using set_of_numbers_type = std::vector< number_type >;

    // TODO: add your stuff here

};

#endif
