#include <iostream>
#include <vector>
using namespace std;

bool existe_sublista(int a[], int n, int soma){
  if (soma == 0) return true;
  if (soma < 0 || n == 0) return false;
  return existe_sublista(a, n-1, soma - a[n-1]) || existe_sublista(a, n-1, soma);
}

int main(){
  int n, soma;
  cin >> n >> soma;

  int* a;
  a = new int[n];
  for (int i=0; i<n; i++) cin >> a[i];

  cout << existe_sublista(a, n, soma) << endl;
  delete[] a;
  return 0;
}