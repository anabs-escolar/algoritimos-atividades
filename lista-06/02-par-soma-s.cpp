#include <iostream>
using namespace std;

// O(n^2)
bool par_soma(int a[], int n,int s){
  for (int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      if (a[i] + a[j] == s) return true;
    }
  }
  return false;
}


int main(){
  int n, s;
  cin >> n >> s;

  int a[n];
  for (int i=0; i<n; i++)
    cin >> a[i];

  if (par_soma(a, n, s)) cout << "S"; else cout << "N"; cout << endl;

  return 0;
}