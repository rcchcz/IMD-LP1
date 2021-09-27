#include "class/game_manager.h"

/**
 * @brief This program runs the game Bar Chart Race
 * 
 * @param argc The number of arguments on command line;
 * @param argv Argumentos passed on comand line
 */
int main( int argc, char * argv[] ){
    GameManager game;

    if(!game.validate( argc, argv )){
        return EXIT_SUCCESS;
    }
    game.summary();
    while(game.quit_game() == SK::Game_status::IN_PROGRESS) 
    {
        game.update();
        game.render();
    }
    game.bye();
    
    return EXIT_SUCCESS;
}
