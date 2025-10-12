#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double n;
  cin >> n;

  double erro =  0.0001;
  double raiz_anterior = n / 2;
  double raiz_atual;

  while (true) {
    raiz_atual = (raiz_anterior + n / raiz_anterior) / 2;

    if (fabs(raiz_atual - raiz_anterior) < erro){
      break;
    }
    raiz_anterior = raiz_atual;
  }
  cout << fixed << setprecision(3);
  cout << raiz_atual << endl;
  return 0;
}