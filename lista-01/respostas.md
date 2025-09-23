1. 

| a | b | soma |
| --- | --- | --- |
| 10 | 20 | 30 |
| -10	| 10 | 0 |
|-2	| -3 | -5 |
| 1000000000 | 1000000000 |	2000000000 |
| -1000000001 | 1000000005 |	4 |
| 2000000000 | 1000000000 |	-1294967296 |
| -1212121212 | -2987654321 |	1002220163 |

O tipo `int` é tipicamente um inteiro de 32 bits, que pode representar valores de -2.147.483.648 a 2.147.483.647. 

Quando o resultado de uma operação excede o limite máximo do tipo de dado, o valor "dá a volta" e recomeça a contagem a partir do limite mínimo. Isso é um **integer overflow**, que acontece no teste 6.

Também, quando o valor ultrapassa o limite inferior e "dá a volta", recomeçando a contagem a partir do limite máximo. Isso é **integer underflow**, que aconte no teste 7.

