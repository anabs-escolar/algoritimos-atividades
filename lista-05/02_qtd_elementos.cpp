#include <iostream>
using namespace std;

// O(n²)
void qtd_elementos(int n, int a[], int b[]){
  for (int i = 0; i < n; i++){
    b[i] = 0;
    for (int j = 0; j < n; j++){
      if (a[i] == a[j]) b[i]++;
    }
  }
}

int main(){
  int n;
  cin >> n;
  
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  int b[n];
  qtd_elementos(n, a, b);

  for (int i = 0; i < n; i++){
    cout << a[i] << " aparece " << b[i] << " vezes depois dele\n";
  }
}
