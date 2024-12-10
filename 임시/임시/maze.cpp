#include "maze.h"
#include <iostream>
#include <cstring>
using namespace std;

void Maze::Initialize(Player& player) {
    player.x = 0;
    player.y = 0;
    strncpy_s(grid[0], COL, "21000011110000000000", COL);
    strncpy_s(grid[1], COL, "11101001001111110000", COL);
    strncpy_s(grid[2], COL, "00101101111100010000", COL);
    strncpy_s(grid[3], COL, "00100001000000010000", COL);
    strncpy_s(grid[4], COL, "00100001111000011110", COL);
    strncpy_s(grid[5], COL, "00100000001000010000", COL);
    strncpy_s(grid[6], COL, "00100000101110010000", COL);
    strncpy_s(grid[7], COL, "00100000101010010000", COL);
    strncpy_s(grid[8], COL, "00111000101000000000", COL);
    strncpy_s(grid[9], COL, "00001100111111110000", COL);
    strncpy_s(grid[10], COL, "00001000100001000000", COL);
    strncpy_s(grid[11], COL, "00001000100001111100", COL);
    strncpy_s(grid[12], COL, "00001111100000000100", COL);
    strncpy_s(grid[13], COL, "00001000000011111000", COL);
    strncpy_s(grid[14], COL, "11111000000010001000", COL);
    strncpy_s(grid[15], COL, "00001000000010000000", COL);
    strncpy_s(grid[16], COL, "00001111100110001000", COL);
    strncpy_s(grid[17], COL, "00000100000010000000", COL);
    strncpy_s(grid[18], COL, "00000100111111100000", COL);
    strncpy_s(grid[19], COL, "00000111100000111113", COL);
}

void Maze::Print(const Player& player) const {
    for (size_t i = 0; i < ROW; i++) {
        for (size_t j = 0; j < COL; j++) {
            if (grid[i][j] == '0') cout << "■";
            else if (grid[i][j] == '1') {
                if (i == player.y && j == player.x) cout << "@";
                else cout << " ";
            }
            else if (grid[i][j] == '2') cout << "☆";
            else if (grid[i][j] == '3') cout << "o";
            else if (grid[i][j] == 'p') cout << "□";
        }
        cout << endl;
    }
    cout << "a 왼쪽, w 위, d 오른쪽, s 아래, M 길찾기, q 종료" << endl;
}
//DFS 구성 코드 있는 부분!!!!!
bool Maze::SolveDFS(int x, int y) {
    if (x < 0 || x >= COL || y < 0 || y >= ROW || grid[y][x] == '0' || grid[y][x] == 'v') return false;
    if (grid[y][x] == '3') return true;

    grid[y][x] = 'v';
    if (SolveDFS(x + 1, y) || SolveDFS(x - 1, y) || SolveDFS(x, y + 1) || SolveDFS(x, y - 1)) {
        grid[y][x] = 'p';
        return true;
    }
    grid[y][x] = '1';
    return false;
}
