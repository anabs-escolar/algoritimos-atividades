#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int divs = 0;
  for (int i = 1; i<=n-1; i++){
    if (n % i == 0){
      divs++;
    }
  }
  cout << divs << endl;
}