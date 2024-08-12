# Jogo

- A solução resolve todos os casos de teste.
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
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MAX = 60;

int N, Q;
vector<int> adj_i{-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> adj_j{-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> v(MAX);
vector<string> step(MAX);

int alive(int i, int j) {
    int alive = 0;

    for (int k = 0; k < 8; k++) {
        int ni = i + adj_i[k];
        int nj = j + adj_j[k];
        
        if (ni < 0 || N <= ni || nj < 0 || N <= nj) continue;  // As posições i e j estão fora da matriz
        if (v[ni][nj] == '1') alive++;
    }
    
    return alive;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v[i] = s;
        step[i] = s;
    }
    
    while (Q--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int n = alive(i, j);
                if (v[i][j] == '0' && n == 3) {
                    step[i][j] = '1';
                }
                if ((v[i][j] == '1' && n < 2) || (v[i][j] == '1' && n > 3)) {
                    step[i][j] = '0';
                }
            }
        }
        for (int i = 0; i < N; i++) {
            v[i] = step[i];
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << v[i] << nl;
    }
    
    return 0;
}
```
