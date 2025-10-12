#include <iostream>
#include <cmath>
using namespace std;

bool primo(int n) {
  if (n <= 1 ) {
    return false;
  }
  for (int d = 2; d <= sqrt(n); d++){
    if (n % d == 0) {
      return false;
    }
  }
  return true;
}

int array_primo(int a[], int n, int primos[]) {
  int count = 0;
  for (int i = 0; i < n; i++){
    if ( primo(a[i]) ){
      primos[count] = a[i];
      count++;
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int primos[n];
  int qtd = array_primo(a, n, primos);

  cout << qtd << endl;
  for (int i = 0; i < qtd; i++){
    cout << primos[i] << " ";
  }
  cout << endl;
}