#include <iostream>
using namespace std;

int maior_diff_arry(int n, int a[]) {
  int maior_dif = 0;                // 1
  for (int i = 0; i < n-1; i++){    // 1 + n-1 + n-1
    int dif = abs(a[i+1] - a[i]);   // n-1
    if (dif > maior_dif)            // n-1
      maior_dif = dif;              // n-1
  }
  return maior_dif;                 // 1
}
// T(n) = 3+5n-5 => 5n-2 => O(n)
int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << maior_diff_arry(n, a) << endl;
  return 0;
}