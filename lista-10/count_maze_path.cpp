#include <iostream>
#include <vector>
using namespace std;

int count_maze_paths(int x, int y, int maze[6][6]){
  if (x<0 || y<0 || x >= 6 || y >= 6)
    return 0;

  if (maze[x][y] == 1) return 0;
  if (maze[x][y] == 2) return 0;
  if (x == 5 && y == 5) return 1;

  maze[x][y] = 2;

  int total = 0;
  total += (count_maze_paths(x+1, y, maze));
  total += (count_maze_paths(x-1, y, maze));
  total += (count_maze_paths(x, y+1, maze));
  total += (count_maze_paths(x, y-1, maze));

  maze[x][y] = 0;
  return total;
}
int main() {
  int maze[6][6];

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      cin >> maze[i][j];

  int x = 0;
  int y = 0;

  cout << count_maze_paths(x, y, maze) << endl;
  return 0;
}
