#include <iostream>
using namespace std;

int main () {
  // MDC
  int a, b;
  cin >> a >> b;
  // Euclides Algorithm
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  cout << a << endl;
  return 0;
}