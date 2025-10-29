#include <chrono>
#include <iostream>
using namespace std;

bool prime(long long n){
  int divs = 0;                         // 1
  for (long long i = 1; i <= n/2; i++)  // n / 2 + n / 2 + 2
    if (n%i == 0)                       // n / 2
      divs = divs + 1;                  // n / 2
  return divs == 1;                     // 1
}
// f(n) = 4n/2 + 4 => 2n + 4
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