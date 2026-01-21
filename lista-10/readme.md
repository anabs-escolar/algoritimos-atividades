## Estrutura Geral de Backtracking em C++

```cpp
void backtrack(EstadoAtual &estado) {
  if (estado é solução completa) {
    salvar ou imprimir estado;
    return;
  }

  for (cada escolha possível) {
    if (escolha é válida) {
      aplicar escolha ao estado;
      backtrack(estado);
      desfazer escolha; // voltar
    }
  }
}
```