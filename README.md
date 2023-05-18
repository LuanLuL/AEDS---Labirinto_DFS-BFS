> Status Development: finished :heavy_check_mark:

# Labirinto por Profundidade (DFS) e Largura (BFS)

## Objetivo 🎯

O objetivo do programa é encontrar uma flag de parada representada pelo símbolo '?' utilizando três métodos de busca diferentes: Depth-First Search (DFS), Breadth-First Search (BFS) e um algoritmo de busca aleatório. Durante a execução do código, os algoritmos irão encontrar obstáculos como paredes represetadas por '#' e perigos '*' na matriz, o que dificultará a localização da flag de parada.

## Lógica :bulb:

O projeto foi desenvolvido para ler várias matrizes de um arquivo de entrada chamado 'input.data'. Cada matriz é quadrada e as informações sobre a quantidade de matrizes, número de linhas e número de colunas são fornecidas na primeira linha do arquivo. Além disso, o projeto inclui a implementação de estruturas dinâmicas de pilha e fila nos arquivos 'pilha.hpp', 'pilha.cpp', 'fila.hpp' e 'fila.cpp'.

Primeiramente, com o objetivo de diminuir os casos de erros e otimizar as verificações, a matriz de entrada é alterada. Essa mudança consiste em cercar a matriz original por parades, possibilitando que todas as posições da matriz possam ser tratadas de forma padronizada. Feito isso, é empregado os diferentes tipos de caminhamento.

### Caminho controlado por DFS

A ideia principal por trás do DFS é explorar o caminho mais profundo, visitando o máximo possível em uma unica direção antes de explorar as outras. Nesse sentido, a ordem de prioridade de orientação consiste em: i)Baixo, ii)Diagonal inferior direita, iii)Direita, iv)Diagonal superior direita, v)Cima vi)Diagonal superior esquerada, vii)Esquerda e viii)Diagonal inferior esquerda. Observe a lógica de caminhamento na Figura 1:


<!--COLOCAR FIGURA DO DFS-->

A implementação do DFS em matrizes é feita com o auxílio de uma pilha. A utilização desse 


### Caminho controlado por BFS

Para o BFS a ideia é percorrer  o caminho utilizando o conseito de  de busca em largura, o que significa que ele visita todos os nós a uma distância k da raiz antes de prosseguir para os nós a uma distância k + 1. Ele utiliza uma fila para controlar a ordem em que os nós são explorados. O primeiro nó a ser visitado é colocado na fila, e então seus vizinhos são adicionados à fila. O processo continua até que todos os nós tenham sido visitados ou a condição de parada seja atingida. Nesse sentido, a ordem de prioridade de orientação é a mesma do DFS citado anteriormente.

<!--COLOCAR FIGURA DO BFS-->

### Caminho aleatorio

O último método tenta achar o vaminho de forma aleatória. Utilizando a função 'random maze' para retornar os números aleatórios definidos no intervalo de (-1,1) dentro da função. O Código foi baseado no trabalho [O labirinto Recorrente](https://github.com/teuswx/O-Labirinto-Recorrente/blob/master/README.md), portanto as ideias implementadas seguem a mesma linha de racioncinio.

## Exemplo de execução :hammer: 

<!--COLOCAR FIGURA DO output junto com os tempos de execução-->

## Análise dos Tempos de Execução :bar_chart:

Tempo de execução do caminho controlado por DFS:

<!--COLOCAR FIGURA DO TEMPO DE EXECUÇÃO-->

Tempo de execução do caminho controlado por BFS:

<!--COLOCAR FIGURA DO TEMPO DE EXECUÇÃO-->

Tempo de execução do caminho aleatório:

<!--COLOCAR FIGURA DO TEMPO DE EXECUÇÃO-->

## Perguntas ❓

**1. qual foi o menor tempo de execução entre os algoritmos?**

**2. Qual o custo computacional gerado por cada algoritmo?**

## Conclusão :ballot_box_with_check:

Durante o desenvolvimento do algoritmo, criou-se três abordagens distintas para resolver o problema de caminhamento em matrizes. Essa diversidade permitiu a comparação e analisasse o desempenho de cada algoritmo. Essa análise foi extremamente valiosa, pois proporcionou um aprendizado significativo sobre técnicas de otimização de código.

Ao comparar os algoritmos, foi possível observar as diferenças em termos de tempo de execução e eficiência. Essa comparação ajudou a identificar as abordagens mais eficientes e compreender quais técnicas de otimização de código são mais adequadas para resolver o problema proposto. Essa experiência proporcionou uma base sólida para o aprimoramento das habilidades do grupo na programação.

## Compilação e Execução :electric_plug:

O programa foi feito de acordo com a proposta e possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


