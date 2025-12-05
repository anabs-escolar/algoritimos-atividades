#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>

class vector {
private:
  int *data;
  unsigned int size_, capacity_, increase_size_;
  bool doubling;

  void increase_capacity() {
    if (this->doubling) {
      this->capacity_ *= 2;
    } else {
      this->capacity_ += this->increase_size_;
    }
    int *new_data = new int[this->capacity_];
    for (unsigned int i = 0; i < this->size_; ++i)
      new_data[i] = this->data[i];
    delete[] this->data;
    this->data = new_data;
  }

public:
  vector(unsigned int inc, bool is_doubling) {
    this->size_ = 0;
    this->capacity_ = 100;
    this->increase_size_ = inc;
    this->doubling = is_doubling;
    this->data = new int[this->capacity_];
  }

  void push_back(int value) {
    if (this->size_ == this->capacity_)
      this->increase_capacity();

    this->data[this->size_++] = value;
  }

  int get_at(int index) {
    if (index < 0 || index >= (int)this->size_)
      throw std::out_of_range("Index out of range");

    return this->data[index];
  }

  unsigned int size() {
    return this->size_;
  }

  unsigned int capacity() {
    return this->capacity_;
  }

  ~vector() {
    delete[] this->data;
  }
};

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Uso: ./vector <increase_size | dup>\n";
    return 1;
  }

  bool doubling = false;
  unsigned int inc = 0;

  std::string arg = argv[1];

  if (arg == "dup") {
    doubling = true;
  } else {
    inc = std::stoi(arg);
    if (inc == 0) {
      std::cerr << "increase_size deve ser > 0\n";
      return 1;
    }
  }

  vector v1(inc, doubling);

  int n;
  auto inicio = std::chrono::high_resolution_clock::now();
  std::cin >> n;

  while (n != -1) {
    v1.push_back(n);
    std::cin >> n;
  }

  auto fim = std::chrono::high_resolution_clock::now();
  long long duracao =
    std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count();

  std::cerr << "ExecTime: " << duracao << "\n";
  std::cout << "ElementsRead: " << v1.size() << "\n";
  std::cout << "FinalCapacity: " << v1.capacity() << "\n";

  return 0;
}
