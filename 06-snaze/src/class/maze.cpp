
#include "maze.h"

void Maze::fruit_spawn(vector<SK::coord> snk_body) {
    vector<SK::coord> aux = Ws;
    // The aux vector will get the ONLY the whitespaces without any part of snake body

    for(auto i = aux.begin() ; i != aux.end(); i++){
        for(auto j = snk_body.begin(); j != snk_body.end(); j++) {
            if((*i)== (*j)){
                aux.erase(i);
                if(i != aux.begin()) i--;
            }        
        }
    }

    fruit = aux[rand() % aux.size()];
}

bool Maze::is_ws(SK::coord fut_pos) {
    return matrix[fut_pos.y][fut_pos.x] != '#' && matrix[fut_pos.y][fut_pos.x] != '.';
}
