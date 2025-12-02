#ifndef LIST_HPP
#define LIST_HPP

struct list{
  private:
  struct list_node{
    int value;
    list_node *next;
  };
  list_node *first, *last;

  public:
  // construtor
  list(){
    this->first = 0;
    this->last = 0;
  };
  // destrutor
  ~list(){
    list_node *current, *to_remove;
    current = this->first;
    while (current != 0){
      to_remove = current;
      current = current->next;
      delete to_remove;
    }
  }
  // inserir no fim
  void append(int value){
    list_node *new_node = new list_node;
    new_node->value = value;
    new_node->next = 0;
    if (this->first == 0)
      this->first = new_node;
    else
      this->last->next = new_node;
    this->last = new_node;
  };
  // inserir no inicio
  void append_first(int value){
    list_node *new_node = new list_node;
    new_node->value = value;
    new_node->next = this->first;
    this->first = new_node;
    if (this->last == 0)
      this->last = new_node;
  }
  // primeiro
  int first_index(){
    if (this->first != 0)
      return this->first->value;
    else
      return -1;
  };
  // ultimo
  int last_index(){
    if (this->last != 0)
      return this->last->value;
    else
      return -1;
  };
  // remover do inicio
  void pop_first(){
    if (this->first == 0) return;
    list_node *to_remove = this->first;
    if (this->last == this->first)
      this->last = 0;
    this->first = this->first->next;
    delete to_remove;
  }
  // remover do fim
  void pop_last(){
    if (this->last == 0) return;
    if (this->first == this->last){
      delete this->first;
      this->first = 0;
      this->last = 0;
    }
    list_node *current = this->first;
    while(current->next != this->last)
      current = current->next;
    current->next = 0;
    delete this->last;
    this->last = current;
  }
  // pecorrer (soma)
  int sum(){
    int ans = 0;
    list_node *current = this->first;
    while (current != 0) {
      ans += current->value;
      current = current->next;
    }
    return ans;
  }

  int lenght(){
    int len = 0;
    list_node *current = this->first;
    while (current != 0) len++;
    return len;
  }

  // index O(n) -  Q02 Gerencia de Memoria
  int index(int x){
    int i = 0;
    list_node *current = this->first;
    while (current != 0){
      if (current->value == x)
        return i;
      i++;
      current = current->next;
    }
    return -1;

    for (list_node *cur = first; cur != 0; cur = cur->next, i++){
      if (cur->value == x)
        return i;
    }
    return -1;
  }

  // remover por valor O(n) - Q03 Gerencia de Memoria
  bool remove(int value){
    if (this->first == 0) return;

    if (this->first->value == value){
      list_node *to_pop = this->first;
      this->first =  first->next;
      if (to_pop == this->last)
        this->last = 0;
      delete to_pop;
      return;
    }

    list_node *cur = this->first;
    while(cur->next != 0 && cur->next->value != value)
      cur = cur->next;

    if (cur->next == 0) return;

    list_node *to_pop = cur->next;

    if (to_pop == this->last){
      this->last = cur;
      this->last->next = 0;
      delete to_pop;
      return;
    }

    cur->next = to_pop->next;
    delete to_pop;
  };
};

#endif