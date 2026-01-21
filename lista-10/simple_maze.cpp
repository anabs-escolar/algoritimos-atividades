#include <iostream>
#include <vector>
using namespace std;

bool simple_maze(int x, int y, int maze[6][6]){
  if (x<0 || y<0 || x >= 6 || y >= 6)
    return false;

  if (maze[x][y] == 1) return false;
  if (maze[x][y] == 2) return false;
  if (x == 5 && y == 5) return true;

  maze[x][y] = 2;

  if (simple_maze(x+1, y, maze)) return true;
  if (simple_maze(x-1, y, maze)) return true;
  if (simple_maze(x, y+1, maze)) return true;
  if (simple_maze(x, y-1, maze)) return true;

  maze[x][y] = 0;
  return false;
}
int main() {
    int maze[6][6];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> maze[i][j];

    int x = 0;
    int y = 0;

    cout << simple_maze(x, y, maze) << endl;
    return 0;
}
