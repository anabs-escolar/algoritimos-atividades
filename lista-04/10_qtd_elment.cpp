#include <iostream>
using namespace std;
//O(n²)
int qtd_elementos(int n, int a[]){
  int num_el = 0;
  for (int i=0; i<n; i++){
    bool first = true;
    for (int j=i+1; j<n; j++){
      if (a[i] == a[j]) first = false;
    }
    if (first) num_el++;
  }
  return num_el;
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << qtd_elementos(n, a) << endl;
}