#include <iostream>
using namespace std;

// O(log n)
int virus(int p, int i = 1){
  if (i >= p) return 0;       // 1
  i = i * 2;                  // 1
  return virus(p, i) + 1;     // log2(n), qnd a funçao dobra/divide por 2
}

int main(){
  int p;
  cin >> p;
  cout << virus(p) << " dia(s)"<< endl;
}
