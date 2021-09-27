/*!
 * @file snake.cpp
 *
 * Implementation of the snake class.
 */

#include "snake.h"

void Snake::set_spawn(SK::coord sp) {
    body.push_back(sp);
}

SK::coord Snake::coord_snake() {
    return body[0];
}

bool Snake::advance(SK::Direct dir, SK::coord fruit) {
    last_tail_pos = body.back();
    last_head_dir = head_dir;
    SK::coord aux = SK::get_pos(body[0],dir);
    switch (dir)
    {
        case SK::Direct::UP:
            head_dir = SK::Direct::UP;
            break;
        case SK::Direct::DOWN:
            head_dir = SK::Direct::DOWN;
            break;
        case SK::Direct::LEFT:
            head_dir = SK::Direct::LEFT;
            break;
        case SK::Direct::RIGHT:
            head_dir = SK::Direct::RIGHT;
            break;
        default:
            break;
    }
    
    body.insert(body.begin(), aux);
    if(fruit == body[0]) {
        return true; 
    }
    body.pop_back();
    return false;
}

char Snake::head_char() {
    switch(head_dir)
    {
        case SK::Direct::UP:
            return '^';
        case SK::Direct::DOWN:
            return 'v';
        case SK::Direct::LEFT:
            return '<';
        case SK::Direct::RIGHT:
            return '>';
        default:
            break;
    }
    return 'O';
}

bool Snake::is_snk(SK::coord pos){
    for(SK::count i = 0; i < body.size(); i++)
    {
        if(body[i] == pos) 
            return true;
    }
    return false;    
}

void Snake::reset() {
    body.clear();
    head_dir = SK::Direct::UP;
}

void Snake::undo() {
    head_dir = last_head_dir;
    body.push_back(last_tail_pos);
    body.erase(body.begin());
}