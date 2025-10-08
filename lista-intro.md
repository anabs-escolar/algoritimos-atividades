# Lista de Introdução à Algoritimos

1. É um conjunto de ações/regras para a solução de um problemas.

2. Entre todas as formas de representar um algoritimo, acredito que a mais adequada seja pseudocódigo, porque a forma de escrita em linguagem natural, além de ser mais fácil de traduzir pra uma linguagem de programação, é mais objetiva e clara sobre o algoritimo representado.

3. A eficência de um algoritimo é como os recursos computacionais sãootimizados, levando em consideração, principalmente, tempo e mémoria.

4.
```
FUNÇÃO primo(numero: INTEIRO) RETORNA BOOLEANO:
    VAR contador = 0

    PARA num DE 1 ATÉ numero FAÇA
        SE numero % num = 0 ENTÃO
            contador = contador + 1
        FIM SE
    FIM PARA

    SE contador = 2 ENTÃO
        RETORNE VERDADEIRO
    SENÃO
        RETORNE FALSO
FIM FUNÇÃO
```

5. Algoritimo que calcula MMC.

6.
```
FUNÇÃO maior_diferenca_array(array: ARRAY DE INTEIROS) RETORNA INTEIRO:
    VAR maior = -1
    VAR comparador = 0

    PARA index DE 1 ATÉ TAMANHO(array) - 1 FAÇA
        comparador = ABS(array[index] - array[index - 1])
        SE comparador > maior ENTÃO
            maior = comparador
        FIM SE
    FIM PARA

    RETORNE maior
FIM FUNÇÃO

```

7.
```
FUNÇÃO existe_par_soma(array: ARRAY DE INTEIROS, s: INTEIRO) RETORNA BOOLEANO:
    VARIÁVEL CONJUNTO vistos = {}

    PARA index DE 0 ATÉ TAMANHO(array) - 1 FAÇA
        VAR elemento = array[index]
        VAR complemento = s - elemento

        SE complemento ESTÁ EM vistos ENTÃO
            RETORNE VERDADEIRO
        FIM SE

        INSERIR elemento EM vistos
    FIM PARA

    RETORNE FALSO
FIM FUNÇÃO
```

8.
```
FUNÇÃO contar_pares_soma(array: ARRAY DE INTEIROS, s: INTEIRO) RETORNA INTEIRO:
    VARIÁVEL INTEIRO contador = 0

    PARA i DE 0 ATÉ TAMANHO(array) - 2 FAÇA
        PARA j DE i+1 ATÉ TAMANHO(array) - 1 FAÇA
            SE array[i] + array[j] = s ENTÃO
                contador = contador + 1
            FIM SE
        FIM PARA
    FIM PARA

    RETORNE contador
FIM FUNÇÃO
```
