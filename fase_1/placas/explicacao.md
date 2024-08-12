# Placas

- A solução resolve todos os casos de teste.
- Complexidade de tempo: **$O(|S|)$**.
  - Onde $|S|$ é o tamanho da string.

Este problema envolve propriedades de strings e caracteres.

Basta verificar se a string lida se encaixa nos parâmetros de alguma placa. Fica mais fácil fazer isso criando uma função para cada uma, que retorna $true$ caso a string se encaixe no padrão da placa.

Se a placa não se encaixar em nenhum padrão, fica implícito que ela é falsa.

## Solução

```cpp
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

bool br(string s) {
    if (s.size() != 8) return false;
    for (int i = 0; i < 3; i++) {
        if (s[i] < 'A' || s[i] > 'Z') return false;
    }
    if (s[3] != '-') return false;
    for (int i = 4; i < 8; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

bool merc(string s) {
    if (s.size() != 7) return false;
    for (int i = 0; i < 3; i++) {
        if (s[i] < 'A' || s[i] > 'Z') return false;
    }
    if (s[3] < '0' || s[3] > '9') return false;
    if (s[4] < 'A' || s[4] > 'Z') return false;
    for (int i = 5; i < 7; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    if (br(s)) {
        cout << 1;
    }
    else if (merc(s)) {
        cout << 2;
    }
    else {
        cout << 0;
    }
    
    cout << nl;
    
    return 0;
}
```