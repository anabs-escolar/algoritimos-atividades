#include <iostream>
using namespace std;

int impares_array(int a[], unsigned int n) {
  int count = 0;
  for (unsigned int i = 0; i < n; ++i) {
    if (a[i] % 2 != 0) {
      count++;
    }
  }
  return count;
}

int main() {
  unsigned int n;
  cin >> n;
  int a[n];
  for (unsigned int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << impares_array(a, n) << endl;
  return 0;
}