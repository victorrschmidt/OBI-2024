# Dança de Formatura

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(N \cdot M + P)$**.

Este problema envolve matrizes.

Considere uma matriz $A_{n \times m}$ 1-indexada, onde os números estão ordenados da esquerda para a direita e de cima para baixo, da seguinte forma:

```math
A =
\begin{bmatrix}
  1_{11}\ & 2_{12}\ & 3_{13}\ & \ldots\ & a_{1m} \\\\
  a_{21}\ & a_{22}\ & a_{23}\ & \ldots\ & a_{2m} \\\\
  \vdots\ & \vdots\ & \vdots\ & \ddots\ & \vdots \\\\
  a_{n1}\ & a_{n2}\ & a_{n3}\ & \ldots\ & a_{nm}
  
\end{bmatrix}
```

Esse é o estado inicial da matriz do problema, e para encontrar o valor em uma posição $i \ j$, a seguinte fórmula pode ser definida:

$$A_{i \ j} = m \cdot (i - 1) + j$$

Além disso, iremos armazenar a numeração das linhas e das colunas, que inicialmente estão ordenadas:

$$linhas[\ ] = [1, 2, 3, \ldots, n]$$

$$colunas[\ ] = [1, 2, 3, \ldots, m]$$

Para cada uma das $P$ mudanças entre posições $a$ e $b$, trocaremos os valores do array de linhas ou colunas (dependendo do tipo de troca) nas posições $a$ e $b$. Após $P$ mudanças (possivelmente 0), para encontrar o valor de $A_{i \ j}$ basta utilizar a fórmula mostrada anteriormente, apenas utilizando $i$ e $j$ como posições nos arrays de linhas e colunas:

$$A_{i \ j} = m \cdot (linha[i] - 1) + coluna[j]$$

Com isso, basta computar as $P$ mudanças e mostrar cada posição da matriz.

## Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<int> linha(N+1), coluna(M+1);

    for (int i = 1; i <= max(N, M); i++) {
        if (i <= N) linha[i] = i;
        if (i <= M) coluna[i] = i;
    }

    for (int i = 0; i < P; i++) {
        char movimento;
        int a, b;
        cin >> movimento >> a >> b;

        if (movimento == 'L') {
            swap(linha[a], linha[b]);
        }
        else {
            swap(coluna[a], coluna[b]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << (M * (linha[i] - 1) + coluna[j]) << ' ';
        }

        cout << '\n';
    }

    return 0;
}
```
