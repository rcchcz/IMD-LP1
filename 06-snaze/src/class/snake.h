#ifndef SNAKE_H
#define SNAKE_H

/**
 *  This class represents the game's snake.
 *
 *  @author Rita C. C. Cruz and Victor Vieira T.
 *  @date September 6th, 2021
 *  @file maze.h
 */

#include "../lib/common.h"

class Snake
{
    public:

        /**
         * @brief Return the snake head coord.
         * @return SK::coord.
         */
        SK::coord coord_snake();
        
        /**
         * @brief Set the head coord.
         */
        void set_spawn(SK::coord sp);
        
        /**
         * @brief Reset the snake, deleting all body.
         * 
         */
        void reset();
        
        /**
         * @brief Move the snake to a direction.
         * 
         * @param dir Direction to go.
         * @param fruit Position of the fruit.
         * @return true If it moved to a fruit.
         * @return false Otherwise.
         */
        bool advance(SK::Direct dir, SK::coord fruit);
        
        /**
         * @brief Undo the last advance.
         */
        void undo();
        
        /**
         * @brief Return the head direction char.
         */
        char head_char();
        
        /**
         * @brief Check if @param pos is on the snake body.
         * 
         * @param pos Coord to check.
         * @return true The Coord is in the snake.
         * @return false Otherwise.
         */
        bool is_snk(SK::coord pos);
        
        /**
         * @brief Snake size.
         */
        SK::count size;
        
        /**
         * @brief Head direction.
         */
        SK::Direct head_dir = SK::Direct::UP;
        
        /**
         * @brief Save the last head direction to use in undo().
         */
        SK::Direct last_head_dir;
        
        /**
         * @brief Save last tail position to use in undo().
         */
        SK::coord last_tail_pos;
        
        /**
         * @brief Snake body, the first element is it's head.
         * 
         */
        vector<SK::coord> body;
};

#endif