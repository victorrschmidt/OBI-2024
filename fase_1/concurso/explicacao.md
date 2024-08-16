# Concurso

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(N)$**.

Este problema envolve arrays.

Primeiro criamos um histograma (array de frequências) $v[\ ]$ que define a quantidade de pessoas que tiraram uma determinada nota na prova, tal que:

$$v[x] = \text{qtd. de candidatos que tiraram } x \text{ na prova}$$

Depois, precisamos verificar a nota de corte. A partir da nota mais alta possível ($100$) até a mais baixa ($0$), iremos somando a quantidade de candidatos que tiraram a nota $i$. Quando a soma for maior ou igual a $K$, a nota $i$ atual será a nota de corte.

## Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> v(101);
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    int soma_atual = 0;
    
    for (int i = 100; i >= 0; i--) {
        soma_atual += v[i];

        if (soma_atual >= K) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
```
