# Retas (soluções parciais)

- As soluções resolvem as subtarefas 1, 2, 3 e 4 (39 pontos).

As soluções consistem em formar todos os pares de retas, encontrar o $x$ do ponto de intersecção de cada par e verificar se $x$ está no intervalo $[X_{1}, \ X{2}]$. Com base nisso, dadas duas retas $r$ e $s$, tal que:

$$r = a_{r} \cdot x + b_{r}$$
$$s = a_{s} \cdot x + b_{s}$$

O ponto de intersecção entre elas é o valor $x$ tal que:

$$x = \frac{b_{s} - b_{r}}{a_{r} - a_{s}}$$

Observe que se o coeficiente angular de $r$ e $s$ forem iguais, ou seja $a_{r} = a_{s}$, teremos uma divisão por $0$, o que nesse caso significa que as retas não possuem nenhum ponto de intersecção. Nesse cenário, consideramos o ponto de intersecção como "infinito".

## Subtarefas 1, 2 e 3

- Complexidade de tempo: $O(N^2)$.

Formamos todos os pares de retas, e para cada um, pegamos a intersecção entre elas e verificamos se $x$ está no intervalo $[X_{1}, \ X_{2}]$. Em caso positivo, incrementamos o contador de intersecções. No final, apenas mostramos o resultado.

### Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;
const double INF = 1e10;
const int MAXN = (int) 1e3 + 10;

struct reta {
    double a, b;
};

vector<reta> v(MAXN);

double interseccao(int i, int j) {
    if (v[i].a == v[j].a) return INF;
    return (v[j].b - v[i].b) / (v[i].a - v[j].a);
}

int main() {
    double N, X1, X2;
    cin >> N >> X1 >> X2;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].a >> v[i].b;
    }
    
    int resp = 0;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double x = interseccao(i, j);
            
            if (X1 <= x && x <= X2) {
                resp++;
            }
        }
    }
    
    cout << resp << '\n';
    
    return 0;
}
```

## Subtarefa 4

- Complexidade de tempo: $O(N)$.

Essa subtarefa especifica que o coeficiente angular das primeiras $N - 1$ retas é igual, ou seja, elas não possuem nenhum ponto de intersecção entre si. Portanto, precisamos apenas parear as primeiras $N - 1$ retas com a última, e para cada par, verificar se existe intersecção.

### Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;
const double INF = 1e10;
const int MAXN = (int) 1e5 + 10;

struct reta {
    double a, b;
};

vector<reta> v(MAXN);

double interseccao(int i, int j) {
    if (v[i].a == v[j].a) return INF;
    return (v[j].b - v[i].b) / (v[i].a - v[j].a);
}

int main() {
    double N, X1, X2;
    cin >> N >> X1 >> X2;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].a >> v[i].b;
    }
    
    int resp = 0;
    
    for (int i = 0; i < N - 1; i++) {
        double x = interseccao(i, N - 1);
            
        if (X1 <= x && x <= X2) {
            resp++;
        }
    }
    
    cout << resp << '\n';
    
    return 0;
}
```
