#include <iostream>
#include <conio.h>
#include "maze.h"
using namespace std;

int main() {
    Player player;
    Maze maze;
    maze.Initialize(player);

    while (true) {
        system("cls");
        maze.Print(player);

        char input = _getch();
        if (input == 'q') {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        if (input == 'M' || input == 'm') {
            if (maze.SolveDFS(player.x, player.y)) {
                cout << "경로를 표시했습니다!" << endl;
            }
            else {
                cout << "탈출 가능한 경로가 없습니다." << endl;
            }
            system("pause");
        }
        else {
            player.Move(input, maze);
            if (player.finish) {
                cout << "탈출 성공! 게임 종료!" << endl;
                break;
            }
        }
    }
    return 0;
}
