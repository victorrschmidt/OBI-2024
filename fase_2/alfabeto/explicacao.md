# Alfabeto

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(|S|)$**.
  - Onde $|S|$ é o tamanho da mensagem.
 
Este problema envolve strings e conjuntos.

Para a mensagem ser válida, é preciso que todos os caracteres presentes na string $mensagem$ também estejam presentes na string $alfabeto$. Podemos interpretar as strings em questão como dois conjuntos $a$ e $m$. Todos os elementos contidos em $m$ precisam estar também contidos em $a$, logo, a seguinte igualdade precisa ser verdadeira:

$$a \cup m = a$$

Podemos colocar os caracteres de $alfabeto$ em um _set_, que possui tempo médio constante para consultas.

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string alfabeto, mensagem;
    cin >> alfabeto >> mensagem;

    set<char> s;

    for (auto letra : alfabeto) {
        s.insert(letra);
    }

    char resposta = 'S';

    for (auto letra : mensagem) {
        if (!s.count(letra)) {
            resposta = 'N';
            break;
        }
    }

    cout << resposta << '\n';

    return 0;
}
```
