#include <iostream>
using namespace std;

int mdc(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int mmc(int a, int b) {
  return (a * b) / mdc(a, b);
}

int main () {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int m = mmc(b, d);
  int n = a*(m/b) + c*(m/d);

  // mim divisior comum
  int div = mdc(n, m);

  n /= div;
  m /= div;

  cout << n << " " << m << endl;
}