# Jogo da Vida

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(N^2 \cdot Q)$**.

Este é um problema que envolve matrizes.

Precisamos saber qual é o estado final da matriz após $Q$ transições. Para fazer a transição entre um estado e outro, verificamos para cada célula $c$ a quantidade de vizinhos vivos que esta possui no estado atual.

A função $alive(i,\ j)$ verifica quantos vizinhos vivos uma célula possui a partir da posição $i$ e $j$ da mesma. Cada célula possui $8$ vizinhos (com exceção das células dos cantos). As coordenadas das células vizinhas de uma célula $c$ possuem valores de $i$ e $j$ que variam em função dos valores $i$ e $j$ de $c$, conforme mostrado abaixo (considere $c$ a célula do meio da matriz).

```math
\begin{bmatrix}
  i-1,\ j-1\ & i-1,\ j\ & i-1,\ j+1 \\\\
  i,\ j-1\ & i,\ j\ & i,\ j+1 \\\\
  i+1,\ j-1\ & i+1,\ j\ & i+1,\ j+1
\end{bmatrix}
```

As variações dos valores de $i$ e $j$ podem ser armazenadas em dois arrays, e para saber a posição de uma célula vizinha, basta somar a variação de $i$ e $j$ em uma mesma posição $k$.

Sabendo a quantidade de vizinhos vivos, basta armazenar o valor da célula no próximo estado em uma matriz auxiliar, e ao final de cada estado, tornar a matriz auxiliar a matriz do estado atual.

## Solução

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 60;

int N, Q;
vector<int> adj_i = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> adj_j = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> matriz(MAXN), matriz_auxiliar(MAXN);

int vizinhos_vivos(int i, int j) {
    int vivos = 0;

    for (int k = 0; k < 8; k++) {
        int ni = i + adj_i[k];
        int nj = j + adj_j[k];

        if (0 <= min(ni, nj) && max(ni, nj) < N && matriz[ni][nj] == '1') {
            vivos++;
        }
    }

    return vivos;
}

int main() {
    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        cin >> matriz[i];
        matriz_auxiliar[i] = matriz[i];    
    }
    
    for (int k = 0; k < Q; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int vivos = vizinhos_vivos(i, j);

                if (matriz[i][j] == '0' && vivos == 3) {
                    matriz_auxiliar[i][j] = '1';
                }
                else if (matriz[i][j] == '1' && (vivos < 2 || vivos > 3)) {
                    matriz_auxiliar[i][j] = '0';
                }
            }
        }

        for (int i = 0; i < N; i++) {
            matriz[i] = matriz_auxiliar[i];
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << matriz[i] << '\n';
    }
    
    return 0;
}
```
