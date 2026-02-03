#include <iostream>
#include <vector>
using namespace std;

bool out_of_maze(int l, int c, int x, int y, vector<vector<int>>& maze){
  if (x<0 || y<0 || x>=l || y>=c)
    return false;
  if (maze[x][y] == 1) return false; // parede
  if (maze[x][y] == 2) return false; // marcado
  if (x == l-1 && y == c-1) return true;

  maze[x][y] = 2;

  if (out_of_maze(l, c, x+1, y, maze)) return true;
  if (out_of_maze(l, c, x-1, y, maze)) return true;
  if (out_of_maze(l, c, x, y+1, maze)) return true;
  if (out_of_maze(l, c, x, y-1, maze)) return true;

  maze[x][y] = 0;
  return false;
}

int main() {
  int l, c;
  cin >> l >> c;

  vector<vector<int>> maze(l, vector<int>(c));

  for (int i=0; i<l; i++)
    for (int j=0; j<c; j++)
      cin >> maze[i][j];

  cout << out_of_maze(l, c, 0, 0, maze) << endl;
  return 0;
}