# Concurso

- A solução resolve todos os casos de teste.
- Complexidade de tempo: **$O(N)$**.

Este problema envolve arrays.

Primeiro criamos um histograma (array de frequências) $v[\ ]$ que define a quantidade de pessoas que tiraram uma determinada nota na prova, tal que:

$$v[x] = \text{qtd. de candidatos que tiraram } x \text{ na prova}$$

Depois, precisamos verificar a nota de corte. A partir da nota mais alta possível ($100$) até a mais baixa ($0$), iremos somar a quantidade de candidatos que tiraram a nota $i$. Quando a soma for maior ou igual a $K$, a nota $i$ atual será a nota de corte.

## Solução

```cpp
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, cur = 0;
    cin >> N >> K;
    vector<int> v(101);
    
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v[n]++;
    }
    
    for (int i = 100; i >= 0; i--) {
        if (cur + v[i] >= K) {
            cout << i << nl;
            return 0;
        }
        cur += v[i];
    }
    
    
    return 0;
}
```
