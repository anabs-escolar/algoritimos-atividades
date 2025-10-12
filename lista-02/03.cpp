#include <iostream>
using namespace std;

void conta_impares(int a[], int n, int impares[], int& qtd_impares) {
  for (int i = 0; i < n; i++) {
    if (abs(a[i]) % 2 == 1) {
      impares[qtd_impares] = a[i];
      qtd_impares = qtd_impares + 1;
    }
  }
}

void conta_pares(int a[], int n, int pares[], int& qtd_pares) {
  for (int i = 0; i < n; i++) {
    if (abs(a[i]) % 2 == 0) {
      pares[qtd_pares] = a[i];
      qtd_pares = qtd_pares + 1;
    }
  }
}

void separar_positivos_negativos(int a[], int n, int positivos[], int negativos[], int& qtd_positivos, int& qtd_negativos){
  qtd_negativos = 0;
  qtd_positivos = 0;

  for (int i = 0; i < n; i++) {
    if (a[n] >= 0) {
      positivos[qtd_positivos] = a[i];
      qtd_positivos++;
    } else if (a[n] < 0) {
      negativos[qtd_negativos] = a[i];
      qtd_negativos++;
    }
  }
}


// int main () {
//   int n, qtd_impares = 0;
//   cin >> n;
//   int a[n], impares[n];
//   for (int i = 0; i < n; i++ ){
//     cin >> a[i];
//   }
//   conta_impares(a, n, impares, qtd_impares);
//   // a qtd de impares fica guardada na referencia qtd_impares
//   cout << qtd_impares << endl;
//   if (qtd_impares > 0) {
//     cout << a[0];
//     for (int i = 1; i < qtd_impares; i++) {
//       cout << " " << a[i];
//     }
//   }
//   return 0;
// }
int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int positivos[n], negativos[n];
  int qtd_positivos = 0, qtd_negativos = 0;

  separar_positivos_negativos(a, n, positivos, negativos, qtd_positivos, qtd_negativos);

  cout << "Quantidade de positivos: " << qtd_positivos << endl;
  if (qtd_positivos > 0) {
      cout << "Positivos: " << positivos[0];
      for (int i = 1; i < qtd_positivos; i++) {
          cout << " " << positivos[i];
      }
      cout << endl;
  }

  cout << "Quantidade de negativos: " << qtd_negativos << endl;
  if (qtd_negativos > 0) {
      cout << "Negativos: " << negativos[0];
      for (int i = 1; i < qtd_negativos; i++) {
          cout << " " << negativos[i];
      }
      cout << endl;
  }

  return 0;
}
