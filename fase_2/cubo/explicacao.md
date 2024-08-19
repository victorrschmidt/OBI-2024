# Cubo Preto

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(1)$**.

Este problema envolve raciocínio lógico e geometria.

Logo de cara já dá pra perceber que a quantidade de cubos com $3$ faces coloridas serão sempre $8$, que são os cubos das pontas das bases. Para encontrar as outras quantidades, basta analisar a progressão das mesmas imaginando cubos pequenos.

$1$ face colorida:
  - $N = 3 \implies 6$
  - $N = 4 \implies 24$
  - Os cubos com $1$ face colorida serão os cubos do meio de cada uma das $6$ faces do cubo maior, que crescem de forma quadrática em função de $N$.
  - $f(N) = (N - 2)^2 \cdot 6$

$2$ faces coloridas:
  - $N = 3 \implies 12$
  - $N = 4 \implies 24$
  - Os cubos com $2$ faces coloridas serão os cubos das bordas do cubo maior (tirando os $8$ que são os de $3$ faces coloridas).
  - $f´(N) = (N - 2) \cdot 12$

Nenhuma face colorida:
  - $N = 3 \implies 1$
  - $N = 4 \implies 8$
  - Os cubos com nenhuma face colorida serão os cubos de "dentro" do cubo maior, que crescem de forma cúbica em função de $N$. Eles também serão simplesmente os cubos que sobrarem.
  - $f´´(N) = (N - 2)^3 = N^3 - f(N) - f´(N) - 8$

Tendo encontrado as funções que definem as quantidades, basta mostrar os resultados.

## Solução

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int m = N - 2;

    int nenhuma = m * m * m;
    int uma = m * m * 6;
    int duas = m * 12;
    int tres = 8;

    cout << nenhuma << '\n';
    cout << uma << '\n';
    cout << duas << '\n';
    cout << tres << '\n';

    return 0;
}
```
