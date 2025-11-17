#include <iostream>
using namespace std;

bool par_soma_s(int n, int a[], int s){
  for (int i = 0; i < n-1; i++){      // 1+ n-1+ n-1
    for (int j = i+1; j < n; j++){    // (1 + n-i-1 + n-i-1)
      if (a[i]+ a[j] == s)            // n(n-1)/2
        return true;                  // 1
    }
  }
  return false;
}
// 1 + n-1 + n-1  ->  2n-1
// 1 + n-i-1 + n-i-1  ->  2n-2i-1
// 2n-1 + 2n-2i-1 + n(n-1)/2  =>  n^2 + n -2 => O(n^2)
//T(n) = 
int main() {
  int n, s;
  cin >> n >> s;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (par_soma_s(n, a, s)) cout << "S" << endl;
  else cout << "N" << endl;

  return 0;
}