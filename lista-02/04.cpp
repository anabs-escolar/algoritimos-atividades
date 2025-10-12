#include <iostream>
using namespace std;

int maior_soma_consecutivos(int a[], int n) {
  int soma_max = a[0] + a[1];

  for (int i = 1; i < n; i++) {
    int soma = a[i] + a[i+1];
    if (soma > soma_max) {
      soma_max = soma;
    }
  }
  return soma_max;
}


int main() {
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << maior_soma_consecutivos(a, n) << endl;

  return 0;
}