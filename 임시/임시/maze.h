#pragma once
#include <vector>

class Player {
public:
    int x = 0;
    int y = 0;
    bool finish = false;

    void Move(char direction, const class Maze& maze); 
};

class Maze {
private:
    static const size_t ROW = 20;
    static const size_t COL = 21;
    char grid[ROW][COL] = {};

public:
    static const size_t getRow() { return ROW; }
    static const size_t getCol() { return COL; }

    void Initialize(Player& player); 
    void Print(const Player& player) const; 
    bool SolveDFS(int x, int y); // DFS로 경로 찾기

    char getGridValue(int x, int y) const { return grid[y][x]; }
    void setGridValue(int x, int y, char value) { grid[y][x] = value; }
};
