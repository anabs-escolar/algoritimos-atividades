#include <iostream>
using namespace std;

int main() {
  float d_circulo_f;
  cin >> d_circulo_f;
  float raio_f = d_circulo_f / 2;
  float area_circulo_f = 3.14159 * (raio_f * raio_f);
  cout.precision(5);
  cout << fixed;
  cout << area_circulo_f << endl;

  double d_circulo;
  cin >> d_circulo;
  double raio = d_circulo / 2;
  double area_circulo = 3.14159 * (raio * raio);
  cout.precision(5);
  cout << fixed;
  cout << area_circulo << endl;
}