#include <iostream>
#include <vector>
using namespace std;

int difficult_maze(int x, int y, int xf, int yf, vector<vector<int>>& maze) {
  int l = maze.size();
  int c = maze[0].size();

  if (x < 0 || y < 0 || x >= l || y >= c) return false;
  if (maze[x][y] == -1) return false;

  if (x == xf && y == yf) return true;

  maze[x][y] = 2;

  if (difficult_maze(x+1, y, xf, yf, maze)) return true;
  if (difficult_maze(x-1, y, xf, yf, maze)) return true;
  if (difficult_maze(x, y+1, xf, yf, maze)) return true;
  if (difficult_maze(x, y-1, xf, yf, maze)) return true;

  maze[x][y] = 0;
  return false;
}

int main() {
  int l, c, xi, yi, xf, yf;
  cin >> l >> c >> xi >> yi >> xf >> yf;

  vector<vector<int>> maze(l, vector<int>(c));

  for (int i = 0; i < l; i++)
  for (int j = 0; j < c; j++)
  cin >> maze[i][j];

  cout << difficult_maze(xi, yi, xf, yf, maze) << endl;
  return 0;
}