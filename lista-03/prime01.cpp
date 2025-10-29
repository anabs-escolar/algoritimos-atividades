#include <chrono>
#include <iostream>
bool prime(long long n) {
  int qty_divs = 0;                     // 1
  for (long long d = 1; d <= n; ++d)    // 2n+2
    if (n % d == 0)                     // n
      qty_divs = qty_divs + 1;          // n
  return qty_divs == 2;                 // 1
}
// f(n) = 4n + 4
int main() {
  long long n;
  std::cin >> n;
  // Início do cronômetro
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