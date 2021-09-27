
#include "common.h"

SK::coord SK::get_pos(SK::coord curr_pos, SK::Direct dir) {
      // Check if the new position is a fruit, whitespace or the previous position.
      SK::coord pos = curr_pos;
      switch(dir)
      {
         case SK::Direct::UP:
            pos.y--;
            break;
         case SK::Direct::DOWN:
            pos.y++;
            break;
         case SK::Direct::LEFT:
            pos.x--;
            break;
         case SK::Direct::RIGHT:
            pos.x++;
            break;
         default:
            break;
      }
      return pos;
   }