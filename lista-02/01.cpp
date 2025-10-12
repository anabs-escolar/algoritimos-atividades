#include <iostream>
using namespace std;

int maior_array(int a[], unsigned int m) {
  int resultado = a[0];
  for (unsigned int i = 1; i < m; i++) {
    if (a[i] > resultado) {
      resultado = a[i];
    }
  }
  return resultado;
}

int maior_array_index(int a[], unsigned int m) {
  int resultado = a[0];
  int index = 0;
  for (unsigned int i = 1; i < m; i++) {
    if (a[i] > resultado) {
      resultado = a[i];
      index = i;
    }
  }
  return index;
}

int main () {
  unsigned int n;
  cin >> n;
  int a[n];
  for (unsigned int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int maior = maior_array_index(a, n);
  cout  << maior << endl;
  return 0;
}