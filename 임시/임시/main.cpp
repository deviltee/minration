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
            cout << "������ �����մϴ�." << endl;
            break;
        }
        if (input == 'M' || input == 'm') {
            if (maze.SolveDFS(player.x, player.y)) {
                cout << "��θ� ǥ���߽��ϴ�!" << endl;
            }
            else {
                cout << "Ż�� ������ ��ΰ� �����ϴ�." << endl;
            }
            system("pause");
        }
        else {
            player.Move(input, maze);
            if (player.finish) {
                cout << "Ż�� ����! ���� ����!" << endl;
                break;
            }
        }
    }
    return 0;
}
