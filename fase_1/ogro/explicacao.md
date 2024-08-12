# Ogro

- A solução resolve todos os casos de teste.
- Complexidade de tempo: **$O(1)$**

Este é um problema simples que envolve somente estruturas condicionais e operações matemáticas.

O Resultado final $x$ será definido pela seguinte recorrência:

```math
x = \begin{cases}
  E+D & E>D  \\
  2 \cdot (D-E) & E \leq D \\
\end{cases}
```

Basta verificar essas condições, e mostrar o resultado.

## Solução

```cpp
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int E, D;
    cin >> E >> D;
    
    cout << (E > D ? E + D : 2 * (D - E)) << nl;
    
    return 0;
}
```
