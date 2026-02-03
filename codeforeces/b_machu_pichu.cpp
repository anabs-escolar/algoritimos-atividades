#include <iostream>
#include <vector>
using namespace std;


void machu_pichu(int l, int c, int n, int m, int& min, int cur_min, vector<vector<int>>& mat){
  if (c < 0 || c >= m) return ;

  cur_min += mat[l][c];
  if (cur_min >= min) return;

  if (l == n){
    min = cur_min;
    return;
  }

  machu_pichu(l-1, c, n, m, min, cur_min, mat);
  machu_pichu(l-1, c-1, n, m, min, cur_min, mat);
  machu_pichu(l-1, c+1, n, m, min, cur_min, mat);
}

int main(){
  int n, m; // linhas colunas
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      cin >> mat[i][j];

  int min = 1000000; // menor trilha

  for (int i=0; i<m; i++)
    machu_pichu(n-1, i, n, m, min, 0, mat);

  cout << min << endl;
  return 0;
}