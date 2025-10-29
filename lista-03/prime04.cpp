#include <iostream>
#include <chrono>
using namespace std;

bool prime(long long n){
  if (n == 1) return false;      // 1
  if (n == 2) return true;       // 1
  if (n % 2 == 0) return false;  // 1
  bool p = true;                 // 1
  long long d = 3;               // 1
  while (p && d <= n/2){         // n/2 + 2
    if (n % d == 0)              // n/2
      p = false;                 // n/2
    d = d + 2;                   // n/2
  }
  return p;                      // 1
}
// f(n) = 4n/2 + 8 => 2n + 8

int main(){
  long long n;
  cin >> n;

  auto beg = std::chrono::high_resolution_clock::now();
  bool p = prime(n);
  // Fim do cronômetro
  auto end = std::chrono::high_resolution_clock::now();

  if (p)
    std::cerr << n << " is prime" << std::endl;
  else
    std::cerr << n << " is not prime" << std::endl;

  auto dur = end - beg; // Duração do cronômetro
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(dur);
  std::cout << duration.count() << std::endl;
  return 0;
}