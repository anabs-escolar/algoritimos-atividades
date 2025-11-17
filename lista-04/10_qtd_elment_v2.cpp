#include <iostream>
using namespace std;

// O(n+m) *m = maior
int qtd_elementos(int n, int a[]){
  int maior = a[0];
  for (int i=0; i<n; ++i){
    if (a[i] > maior) maior = a[i];
  }

  int c[maior+1];
  for (int i=0; i<n; ++i) c[a[i]] = 1;

  int qtd = 0;
  for (int i = 0; i<=maior; i++) qtd += c[i];
  return qtd;
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