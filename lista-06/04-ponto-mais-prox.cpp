#include <iostream>
#include <cmath>
using namespace std;

struct Coordenada{
  double x, y;
};

double distancia(Coordenada a, Coordenada b){
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

//O(n^2)
double menor_distancia(Coordenada c[], int n){
  double menor = distancia(c[0], c[1]);
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; i++){
      double d = distancia(c[i], c[j]);
      if (d < menor) menor = d;
    }
  }
  return menor;
}

int main(){
  int n;
  cin >> n;
  Coordenada c[n];
  for (int i = 0; i < n; i++)
    cin >> c[i].x >> c[i].y;

  cout << "Menor distancia é " << menor_distancia(c, n) << endl;

  return 0;
}