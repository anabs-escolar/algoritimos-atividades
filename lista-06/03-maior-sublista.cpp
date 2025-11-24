#include <iostream>
using namespace std;

//O(n^2)
int maior_sublista_contigua(int a[], int n){
  int maior_soma = 0;
  int soma = 0;
  for (int i=1; i<n; i++){
    for (int j=i+1; j<n; j++){
      soma = soma + a[j];
      if (soma > maior_soma) maior_soma = soma;
    }
  }
  return maior_soma;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << maior_sublista_contigua(a, n) << endl;
  return 0;
}