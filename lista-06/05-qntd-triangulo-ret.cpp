#include <iostream>
#include <cmath>
using namespace std;

struct Coordenada{
  double x, y;
};

double distancia(Coordenada a, Coordenada b){
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// O(n^3)
int qntd_triangulos_retangulos(Coordenada c[], int n){
  int qntd = 0;
  for (int i=1; i<n; i++){
    for (int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
        double AB, AC, BC;
        AB = distancia(c[i], c[j]);
        AC = distancia(c[j], c[k]);
        BC = distancia(c[i], c[k]);

        double h = AB, c1 = AC, c2 = BC;
        if (AC > h) {h = AC; c1 = AB; c2 = BC;}
        if (BC > h) {h = BC; c1 = AC; c2 = AB;}

        if (h*h == c1*c1 + c2*c2) qntd++;
      }
    }
  }
  return qntd;
}

int main(){
  int n;
  cin >> n;
  Coordenada c[n];
  for (int i=0; i<n; i++){
    cin >> c[i].x >> c[i].y;
  }
  cout << qntd_triangulos_retangulos(c, n) << endl;
  return 0;
}