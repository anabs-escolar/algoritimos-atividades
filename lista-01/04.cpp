#include <iostream>
using namespace std;

int main() {
  int metros, postes;
  cin >> metros >> postes;
  // quant. de intervalos
  int q = metros / postes;
  int resto = metros % postes;
  int quant_postes, ultima_distancia;
  if (resto == 0) {
    quant_postes = q + 1;
    ultima_distancia = postes;
  }
  else {
    quant_postes = q + 2;
    ultima_distancia = resto;
  }
  cout << quant_postes << " " << ultima_distancia << endl;
}