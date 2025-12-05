#ifndef ARRAY_HPP
#define ARRAY_HPP

struct vector_array {
  private:
  int *data;
  int capacity;
  int size;

  void increase_size() {
    int new_cap = this->capacity * 2;
    int *new_data = new int[new_cap];

    for (int i = 0; i < this->size; i++)
      new_data[i] = this->data[i];

    delete[] this->data;
    this->data = new_data;
    this->capacity = new_cap;
  }

  public:
  vector_array() {
    this->capacity = 4;
    this->size = 0;
    this->data = new int[this->capacity];
  }
  ~vector_array() {
    delete[] this->data;
  }

  void append(int value) {
    if (this->size == this->capacity)
      this->increase_size();
    this->data[this->size++] = value;
  }

  void append_first(int value) {
    if (this->size == this->capacity)
      this->increase_size();

    for (int i = this->size; i > 0; i--)
      this->data[i] = this->data[i - 1];

    this->data[0] = value;
    this->size++;
  }

  int first_index() {
    if (this->size == 0) return -1;
      return this->data[0];
  }

  int last_index() {
    if (this->size == 0) return -1;
      return this->data[this->size - 1];
  }

  void pop_first() {
    if (this->size == 0) return;

    for (int i = 0; i < this->size - 1; i++)
      this->data[i] = this->data[i + 1];

    this->size--;
  }

  void pop_last() {
    if (this->size == 0) return;
      this->size--;
  }

  int sum() {
    int s = 0;
    for (int i = 0; i < this->size; i++)
      s += this->data[i];
    return s;
  }

  int length() {
    return this->size;
  }

  int index(int x) {
    for (int i = 0; i < this->size; i++)
    if (this->data[i] == x)
      return i;
    return -1;
  }

  bool remove(int value) {
    int pos = this->index(value);
    if (pos == -1) return false;

    for (int i = pos; i < this->size - 1; i++)
      this->data[i] = this->data[i + 1];

    this->size--;
    return true;
  }
};

#endif
