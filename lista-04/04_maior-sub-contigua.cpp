#include <iostream>
using namespace std;

int maior_sub_contigua(int n, int a[]){
  if (n == 0) return 0;
  int max = 1;
  int atual = 1;
  for (int i = 1; i < n; i++){    // 1 + n + n
    if (a[i] >= a[i-1])           // n
      atual++;                    // n
    else { 
      if (atual > max)
        max = atual;
      atual = 1;
    }
  }
  if (atual > max)                // 1
    max = atual;                  // 1
  return max;
}
//T(n) = 4n+3 => O(n)
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  cout << maior_sub_contigua(n, a) << endl;
  return 0;
}