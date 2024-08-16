# Ogro

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(1)$**.

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
#include <iostream>
using namespace std;

int main() {
    int E, D;
    cin >> E >> D;
    
    if (E > D) {
        cout << E + D << '\n';
    }
    else {
        cout << 2 * (D - E) << '\n';
    }
    
    return 0;
}
```
