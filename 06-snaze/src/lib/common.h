#ifndef COMMOM_H
#define COMMOM_H

/**
 *  This is a set of common definition for all the classes.
 *  This is to avoid circular referencing.
 *
 *  @author Rita C. C. Cruz and Victor Vieira T.
 *  @date September 6th, 2021
 *  @file common.h
 */

#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::stoul;
using std::stoi;
using std::getline;

#include <string.h> //strcmp

#include <stdlib.h>
using std::rand;

#include <sstream> // For the stringstream.
using std::ostringstream;
using std::stringstream;

#include <vector>
using std::vector;


#include <stack>
using std::stack;

#include <chrono>
using std::chrono::milliseconds;

#include <thread>
using std::this_thread::sleep_for;

#include <fstream> 
using std::ifstream;

#include <algorithm>
#include <random>

 namespace SK {

   using count = unsigned short int;

   enum Game_status {
      LOSE = 1,
      WON,
      IN_PROGRESS
   };
   enum Game_mode {
      BACKTRACKING =0,
      RANDOM
   };

   enum Direct {
      UP = 0,
      LEFT,
      DOWN,
      RIGHT,
      FAKE
   };

   struct coord
   {
      count x;
      count y;

      /**
       * @brief Override == operator for coord type.
       */
      inline bool operator==(coord a) { return (a.x == x && a.y == y); }

      /**
       * @brief Override != operator for coord type.
       */
      inline bool operator!=(coord a) { return !(*this == a); }

      /**
       * @brief Override = operator for coord type.
       */
      inline void operator=(coord a) {
         x = a.x;
         y = a.y;
      }
   };

   /**
    * @brief This struct is used in the Backtracking mode.
    */
   struct Move {

      Direct dir;

      SK::coord pos_;

   };

   /**
    * @brief Givan a position and a direction, returns the next position
    * 
    * @param curr_pos Start position
    * @param dir Direction to go
    * @return The Next position
    */
   coord get_pos(coord curr_pos, Direct dir);
   
 }; // SK

 #endif
 