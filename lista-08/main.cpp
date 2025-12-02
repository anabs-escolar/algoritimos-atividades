#include "lista-ligada.hpp"
#include <iostream>
using namespace std;

int main(){
  list L;

  L.append(10);
  L.append(20);

  cout << L.first_index() << endl;
  cout << L.last_index() << endl;
  cout << L.sum() << endl;
  
}