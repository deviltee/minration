#include "maze.h"

void Player::Move(char direction, const Maze& maze) {
    switch (direction) {
    case 'a': case 'A':
        if (x - 1 >= 0 && maze.getGridValue(x - 1, y) != '0') x--;
        break;
    case 'd': case 'D':
        if (x + 1 < Maze::getCol() && maze.getGridValue(x + 1, y) != '0') x++;
        break;
    case 'w': case 'W':
        if (y - 1 >= 0 && maze.getGridValue(x, y - 1) != '0') y--;
        break;
    case 's': case 'S':
        if (y + 1 < Maze::getRow() && maze.getGridValue(x, y + 1) != '0') y++;
        break;
    }
    if (maze.getGridValue(x, y) == '3') finish = true; 
}
