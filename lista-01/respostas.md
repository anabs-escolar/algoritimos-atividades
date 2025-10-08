## 1.

| a | b | soma |
| --- | --- | --- |
| 10 | 20 | 30 |
| -10	| 10 | 0 |
|-2	| -3 | -5 |
| 1000000000 | 1000000000 |	2000000000 |
| -1000000001 | 1000000005 |	4 |
| 2000000000 | 1000000000 |	-1294967296 |
| -1212121212 | -2987654321 |	1. 

| a | b | soma |
| --- | --- | --- |
| 10 | 20 | 30 |
| -10	| 10 | 0 |
|-2	| -3 | -5 |
| 1000000000 | 1000000000 |	2000000000 |
| -1000000001 | 1000000005 |	4 |
| 2000000000 | 1000000000 |	-1294967296 |
| -1212121212 | -2987654321 |	1. 

| a | b | soma |
| --- | --- | --- |
| 10 | 20 | 30 |
| -10	| 10 | 0 |
|-2	| -3 | -5 |
| 1000000000 | 1000000000 |	2000000000 |
| -1000000001 | 1000000005 |	4 |
| 2000000000 | 1000000000 |	-1294967296 |
| -1212121212 | -2987654321 |	935362436 |

O tipo `int` é tipicamente um inteiro de 32 bits, que pode representar valores de -2.147.483.648 a 2.147.483.647. 

Quando o resultado de uma operação excede o limite máximo do tipo de dado, o valor "dá a volta" e recomeça a contagem a partir do limite mínimo. Isso é um **integer overflow**, que acontece no teste 6.

Também, quando o valor ultrapassa o limite inferior e "dá a volta", recomeçando a contagem a partir do limite máximo. Isso é **integer underflow**, que aconte no teste 7.
 |

O tipo `int` é tipicamente um inteiro de 32 bits, que pode representar valores de -2.147.483.648 a 2.147.483.647. 

Quando o resultado de uma operação excede o limite máximo do tipo de dado, o valor "dá a volta" e recomeça a contagem a partir do limite mínimo. Isso é um **integer overflow**, que acontece no teste 6.

Também, quando o valor ultrapassa o limite inferior e "dá a volta", recomeçando a contagem a partir do limite máximo. Isso é **integer underflow**, que aconte no teste 7.
  |

O tipo `int` é tipicamente um inteiro de 32 bits, que pode representar valores de -2.147.483.648 a 2.147.483.647. 

Quando o resultado de uma operação excede o limite máximo do tipo de dado, o valor "dá a volta" e recomeça a contagem a partir do limite mínimo. Isso é um **integer overflow**, que acontece no teste 6.

Também, quando o valor ultrapassa o limite inferior e "dá a volta", recomeçando a contagem a partir do limite máximo. Isso é **integer underflow**, que aconte no teste 7.

## 2.

| Entrada   | Saída |
| ---       | ---   |
| 2 3       | 10    |
| 5 5       | 20    |
| 1654 2456 | 8220  |
| 0 7       | 14    |
| 0 0       | 0     |

## 3.


| Diâmetro | Float | Double |
| --- | --- | --- |
| 1.00000 | 0.78540 | 0.78540 |
| 10.00000 | 78.53975 | 78.53975 |
| 50000.00000 | 1963493760.00000 | 1963493750.00000 |
| 100000.00000 | 7853975040.00000 | 7853975000.00000 |
| 200000.00000 | 31415900160.00000 | 31415900000.00000 |
| 1.56780 | 1.93050 | 1.93050 |
| 123.45678 | 11970.69629 | 11970.69610 |
| 12345678.87654 | 119706979663872.00000 | 119706978009578.81250 |
| 2000000000.88888 | 119706979663872.00000 | 119706978009578.81250 |