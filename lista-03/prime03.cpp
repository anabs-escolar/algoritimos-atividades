#include <chrono>
#include <iostream>
using namespace std;

bool prime(long long n){
  if (n == 1) return false;           // 1
  if (n == 2) return true;            // 1
  if (n%2 == 0) return false;         // 1
  int q_divs = 1;                     // 1
  for (long long i=3; i <= n/2; i++)  // 2n/2 + 2
    if (n%i == 0)                     // n/2
      q_divs = q_divs + 1;            // n/2
  return q_divs == 1;                 // 1
}
// f(n) = 4n/2 + 7 => 2n + 7
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