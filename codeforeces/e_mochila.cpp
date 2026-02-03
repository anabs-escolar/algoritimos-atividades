#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct item{
  int peso;
  double valor;
};


void mochila(int index, int peso_atual, double valor_atual, double& m_valor, int capacidade, vector<item>& itens){
  if (peso_atual > capacidade) return;

  if (size_t(index) == itens.size()){
    if (valor_atual > m_valor)
      m_valor = valor_atual;
    return;
  }
  mochila(index +1, peso_atual, valor_atual, m_valor, capacidade, itens);
  mochila(index+1, peso_atual+ itens[index].peso, valor_atual+ itens[index].valor, m_valor, capacidade, itens);
}

int main(){
  int n, c;
  cin >> n >> c;

  vector<item> itens(n);
  for (int i=0; i<n; i++)
    cin >> itens[i].peso >> itens[i].valor;

  double melhor = -1;
  mochila(0, 0, 0, melhor, c, itens);

  cout << fixed << setprecision(2) << melhor << endl;
  return 0;
}