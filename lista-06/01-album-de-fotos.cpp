#include <iostream>
using namespace std;

// O(1)
bool f1(int l, int h, int l1, int l2, int h1, int h2){
  int ls = l1+l2;
  int hs = h1+h2;

  if ((ls == l || ls == h) && (hs == l || hs == h))
    return true;
  else if ((l1+h2 == l || l1+h2 == h) && (l2+h1 == l || l2+h2 == h))
    return true;
  return false;
}

bool album_de_fotos(int l, int h, int l1, int l2, int h1, int h2){
  if (l1+l2 <= l && max(h1,h2) <= h ) return true;
  if (h1+h2 <= h && max(l1,l2) <= l ) return true;
  return false;
}


int main(){
  int X, Y;
  int L1, H1;
  int L2, H2;

  cin >> X >> Y;
  cin >> L1 >> H1;
  cin >> L2 >> H2;

  if (album_de_fotos(X, Y, L1, L2, H1, H2)) cout << "S" << endl;
  else cout << "N" << endl;

  return 0;
}