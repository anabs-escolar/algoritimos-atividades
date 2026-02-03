#include <iostream>
#include <vector>
using namespace std;

void piramid(int l, int start, int n, int& min, int cur_min, vector<vector<int>>& mat){
  if (cur_min >= min) return;
  
  if (l == n){
    if (cur_min < min)
      min = cur_min;
    return;
  }

  int size = l +1;

  for (int c = start - 1; c <= start; c++) {
    if (c >= 0 && c + size <= n) {

      int soma = 0;
      for (int j = 0; j < size; j++)
        soma += mat[l][c + j];

      piramid(l + 1, c, n, min, cur_min + soma, mat);
    }
  }
}

int main(){
  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> mat[i][j];

  int min = 100000;

  for (int c=0; c<n; c++)
    piramid(0, c, n, min, 0, mat);

  cout << min << endl;
  return 0;
}