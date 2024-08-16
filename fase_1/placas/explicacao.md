# Placas

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(1)$**.

Este problema envolve propriedades de strings e caracteres.

Basta verificar se a string lida se encaixa nos parâmetros de alguma placa. Fica mais fácil fazer isso criando uma função para cada uma, ambas retornando $true$ caso a string se encaixe no padrão da placa.

Se a placa não se encaixar em nenhum padrão, fica implícito que ela é falsa.

## Solução

```cpp
#include <iostream>
#include <string>
using namespace std;

bool brasileira(string placa) {
    if (placa.size() != 8) return false;

    for (int i = 0; i < 8; i++) {
        if (i < 3 && (placa[i] < 'A' || placa[i] > 'Z')) return false;
        else if (i == 3 && placa[i] != '-') return false;
        else if (i > 3 && (placa[i] < '0' || placa[i] > '9')) return false;
    }

    return true;
}

bool mercosul(string placa) {
    if (placa.size() != 7) return false;

    for (int i = 0; i < 7; i++) {
        if (i < 3 && (placa[i] < 'A' || placa[i] > 'Z')) return false;
        else if (i == 3 && (placa[i] < '0' || placa[i] > '9')) return false;
        else if (i == 4 && (placa[i] < 'A' || placa[i] > 'Z')) return false;
        else if (i > 4 && (placa[i] < '0' || placa[i] > '9')) return false;
    }

    return true;
}

int main() {
    string placa;
    cin >> placa;
    
    if (brasileira(placa)) {
        cout << 1;
    }
    else if (mercosul(placa)) {
        cout << 2;
    }
    else {
        cout << 0;
    }
    
    cout << '\n';
    
    return 0;
}
```
