# Jogo do Poder (solução parcial)

- A solução resolve as subtarefas $1$, $2$, $3$ e $5$ ($44$ pontos).
- Complexidade de tempo: **$O(N^2 \cdot M^2 \cdot log(N \cdot M))$**.

Esta solução utiliza um algoritmo de busca em largura (_breadth-first search_) utilizando uma fila de prioridade (_priority queue_).

Para cada uma das $N \cdot M$ posições da matriz, iremos verificar o máximo de valor que ela pode acumular, passando por todas as posições adjacentes e armazenando os valores em ordem crescente na fila. 

As posições adjacentes de uma posição com valores $i \ j$ são:

```math
\begin{bmatrix}
  \cdots & i-1,\ j & \cdots \\\\
  i,\ j-1 & i,\ j & i,\ j+1 \\\\
  \cdots  & i+1,\ j  & \cdots
\end{bmatrix}
```

Caso o menor valor da fila seja maior que o valor atual, significa que o valor máximo já foi alcançado.

Se a fila ficar vazia, significa que toda a matriz foi processada, e a posição pode acumular a soma total da matriz.

Ao final de cada iteração, basta mostrar o valor acumulado.

## Solução

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int var_i[] = {-1, 0, 1, 0};
int var_j[] = {0, 1, 0, -1};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matriz(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<vector<bool>> visitado(N, vector<bool>(M));
            priority_queue<vector<int>> pq;
            visitado[i][j] = true;
            pq.push({0, i, j});
            int soma_atual = matriz[i][j];

            while (!pq.empty()) {
                int valor = -pq.top()[0];
                int _i = pq.top()[1];
                int _j = pq.top()[2];
                pq.pop();

                if (soma_atual < valor) break;

                soma_atual += valor;

                for (int k = 0; k < 4; k++) {
                    int ni = _i + var_i[k];
                    int nj = _j + var_j[k];

                    if (0 <= min(ni, nj) && ni < N && nj < M && !visitado[ni][nj]) {
                        visitado[ni][nj] = true;
                        pq.push({-matriz[ni][nj], ni, nj});
                    }
                }
            }

            cout << soma_atual << ' ';
        }

        cout << '\n';
    }

    return 0;
}
```
