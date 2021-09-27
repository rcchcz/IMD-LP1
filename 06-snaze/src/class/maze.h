#ifndef MAZE_H
#define MAZE_H

/**
 *  This class represents the game's maze.
 *
 *  @author Rita C. C. Cruz and Victor Vieira T.
 *  @date September 6th, 2021
 *  @file maze.h
 */


#include  "../lib/common.h"

class Maze {
      public:
            SK::count row;
            SK::count collumn;
            
            /**
             * @brief Matrix with the vector's elements;
             */
            vector<vector<char>> matrix; 
            
            /**
             * @brief Snake spwan.
             */
            SK::coord spawn;
            
            /**
             * @brief Postion of the fruit.
             * {0,0} is a invalid position.
             */
            SK::coord fruit{0,0};
            
            /**
             * @brief Vector of whitespaces.
             * 
             */
            vector<SK::coord> Ws;
            
            /**
             * @brief Eaten foods.
             */
            SK::count eaten = 0;
            
            /**
             * @brief Fruit spawn.
             * @param snk_body The snake body.
             */
            void fruit_spawn( vector<SK::coord> snk_body);
            
            /**
             * @brief Check if is whitespace
             * 
             * @param fut_pos Fruit position.
             */
            bool is_ws(SK::coord fut_pos);
};

#endif