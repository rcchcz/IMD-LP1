#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

/**
 * This class is responsable to do the main actions of the game.
 *
 * @author Rita C. C. Cruz and Victor Vieira T.
 * @date September 6th, 2021
 * @file game_manager.h
 * 
 */


#include "../lib/common.h"
#include "snake.h"
#include "maze.h"


/// This the main class/struct that represents the game manager.
class GameManager{
 //== Public methods
    public:
        
        /**
        * @brief This functions validate the command line arguments, and call the function 
        *  analyze_file;
        * @param argc Number of arguments.
        * @param argv Arguments passed by command line.
        * @return true Success.
        * @return false Something went wrong.
        */
        bool validate(int argc, char *argv[]);

        /**
        * @brief Return the current game status.
        */
        SK::Game_status quit_game(); 
        
        /**
        * @brief Make the snake movement, based on the type of game : Random or Backtracking
        * If is not possible to find a way using Backtracking, the snake will move Random avoiding lost it's life
        */
        void update();
        
        /**
        * @brief End the game.
        * Occurs when the player successfully completes all levels or when he loses all lives.
        */
        void bye();

        /**
        * @brief Print the level and its information.
        */
        void render();
        
        /**
        * @brief Print a summary of the game's information at that moment.
        */
        void summary();
        
        
    private:
        
        /**
         * @brief Set game fps.
         * @param input Value entered by user.
         */
        bool set_fps(int input);
        
        /**
         * @brief Set snake number of lives.
         * @param input Value entered by user.
         */
        bool set_lives(int input);
        
        /**
         * @brief Set game number of foods.
         * @param input Value entered by user.
         */
        bool set_foods(int input);

        /**
         * @brief Set game mode: backtracking or random.
         * @param input Set by user.
         */
        bool set_playertype(string input);

        /**
         * @brief Check if the past maze is within the accepted margins.
         * The maze can contain between [1,100] rows and columns.
         * @param input Value entered by user.
         */
        int validate_row_collumn(string input);

        /**
         * @brief Checks if a string is a number.
         * @param s String to be parsed.
         */
        bool is_number(const std::string& s);

        /**
         * @brief Move the snake randomly.
         */
        void move_rand();

        /**
         * @brief This function is a intermediate between choose and the update function.
         */
        void move_smart();

        /**
         * @brief This function finds the next snake position, and add it's to the variable paths.
         * 
         * @param snk_bdy Snake Body
         * @return true If the fruit was found
         * @return false Otherwise
         */
        bool choose(Snake snk_bdy);
        
        /**
         * @brief Controls printing based on fps.
         * @param fps Number of frames per second.
         */
        void timing(SK::count fps);
    
        /**
         * @brief This function open the file and collect all information 
         * passing to the dataframe class.
         * @param path file location
         * @return true success
         * @return false If something went wrong
         */
        bool analyze_file(char * path);

        /**
         * @brief Auxiliary method for debug.
         * Prints the direction.
         */
        void print_dir(SK::count i);

        /**
         * Sets the priority of directions based on the relative positions of the snake and the fruit.
         * @param snk_head Coordinate of the snake's head.
         * @return Vector with the four directions in descending order of priority.
         */
        vector<int> prior_list(SK::coord snk_head);

        SK::count fps = 24; 
        SK::count lives = 5; 
        SK::count foods = 10; 
        SK::count combo = 1; 
        SK::count score = 0;
        SK::count curr_lvl = 0; 
        vector<SK::Move> paths;
        vector<SK::Move> all_paths;
        SK::count num_path = 1;
        SK::Game_status status = SK::Game_status::IN_PROGRESS;
        bool backtracking = true;
        SK::Game_mode player_type = SK::Game_mode::BACKTRACKING;
        vector<Maze> Levels;
        vector<vector<char>> image;
        Snake m_snake;
};
#endif