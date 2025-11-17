#include <iostream>
using namespace std;

// O(log n)
int tempo_perda_massa(int t, double mi){
  if (mi<= 1) return 0;                   // 1 + 1
  mi =  mi/2;                             // 1
  return tempo_perda_massa(t, mi) + t;    // log2(n)
}

int main(){
  int t; double mi;
  cin >> t >> mi;
  cout << tempo_perda_massa(t, mi) << " segundo(s)"<< endl;
}
