# Retas (soluções parciais)

- As soluções resolvem as subtarefas 1, 2, 3 e 4 (39 pontos).

A solução se baseia em verificar todos os pares de retas e encontrar o ponto de intersecção. Dadas duas retas $r$ e $s$, tal que:

$$r = a_{r} \cdot x + b_{r}$$
$$s = a_{s} \cdot x + b_{s}$$

O ponto de intersecção entre elas é o valor $x$ tal que:

$$x = \frac{b_{s} - b_{r}}{a_{r} - a_{s}}$$

Obs: se o coeficiente angular de $r$ e $s$ forem iguais, ou seja $a_{r} = a_{s}$, as retas não possuem nenhum ponto de intersecção. Nesse caso, consideramos o ponto de intersecção como 'infinito'.

## Subtarefas 1, 2 e 3

- Complexidade de tempo: $O(N^2)$.

Verificamos todos os pares de retas, pegamos a intersecção $x$ entre elas (se existir) e verificamos se $x$ está no intervalo $[X_{1}, \ X_{2}]$. Em caso positivo, incrementamos o contador de intersecções.

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
    double N, L, R;
    cin >> N >> L >> R;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].a >> v[i].b;
    }
    
    int resp = 0;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double x = interseccao(i, j);
            
            if (L <= x && x <= R) {
                resp++;
            }
        }
    }
    
    cout << resp << nl;
    
    return 0;
}
```

## Subtarefa 4

- Complexidade de tempo: $O(N)$.

Essa subtarefa especifica que o coeficiente angular das primeiras $N - 1$ retas é igual, ou seja, elas não se interseccionam entre si. Portanto, precisamos apenas parear as primeiras $N - 1$ retas com a última reta, e verificar se existe intersecção.

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
    double N, L, R;
    cin >> N >> L >> R;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].a >> v[i].b;
    }
    
    int resp = 0;
    
    for (int i = 0; i < N - 1; i++) {
        double x = interseccao(i, N - 1);
            
        if (L <= x && x <= R) {
            resp++;
        }
    }
    
    cout << resp << '\n';
    
    return 0;
}
```
