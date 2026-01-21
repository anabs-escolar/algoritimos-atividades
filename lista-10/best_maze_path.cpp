#include <iostream>
#include <vector>
using namespace std;

void count_maze_paths(int x, int y, int maze[6][6], int steps, int& best){
  if (x<0 || y<0 || x >= 6 || y >= 6) return;
  if (maze[x][y] == 1) return;
  if (maze[x][y] == 2) return;

  if (x == 5 && y == 5) {
    if (steps < best)
      best = steps;
    return;
  };

  maze[x][y] = 2;

  count_maze_paths(x+1, y, maze, steps+1, best);
  count_maze_paths(x-1, y, maze, steps+1, best);
  count_maze_paths(x, y+1, maze, steps+1, best);
  count_maze_paths(x, y-1, maze, steps+1, best);

  maze[x][y] = 0;
}
int main() {
    int maze[6][6];

    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
        cin >> maze[i][j];

    int x = 0;
    int y = 0;
    int best = 100;
    int spets = 0;
    count_maze_paths(x, y, maze, spets, best);

    if (best == 100)
      cout << -1 << endl;
    else
      cout << best << endl;

    return 0;
}
