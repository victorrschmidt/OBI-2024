# Burocracia (solução parcial não submetida)

- A solução resolve(ria) a subtarefa 3 (28 pontos).

## Relato pessoal

Foram gastos cerca de 15 minutos para elaborar essa solução, e um adicional de 2 horas (quase metade do tempo de prova) para tentar encontrar o caso de borda que fazia o algoritmo dar _segmentation fault_. Após chegar em casa e analisar com mais calma, foi possível identificá-lo.

## Sobre a solução

- Complexidade de tempo: $(N \cdot Q)$.

A solução consiste em representar o grafo a partir de uma lista de adjacências. Após isso, criamos uma função para determinar a profundidade (_depth_) de cada vértice, começando pela raíz da árvore e travessando todos os vértices.

Para a responder a _query_ "1 v k", iremos subir a árvore a partir de $v$ até encontrar o número do nobre que possui profundidade $p_{v} - k$, onde $p_{v}$ é a profundidade de $v$. Após isso, basta mostrá-lo.

Para responder a _query_ "2 v", iremos descer a árvore a partir de $v$ e pegar todos os seus filhos, isto é, todos os vértices da sub-árvore que possui $v$ como raiz. Após isso, iremos refazer as listas de adjacências de todos os vértices dessa sub-árvore, conectando a raiz diretamente com os outros vértices.

### Observação

Ao refazer as listas de adjacências, é necessário pegar o vértice pai de $v$ para recolocá-lo na lista. Entretanto, se o vértice $v$ for $1$ (a raiz da árvore principal), este não terá um vértice pai. Esse caso específico deve ser verificado para evitar _segmentation fault_.

## Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1010;

vector<vector<int>> adj(MAXN);
vector<int> filhos;
int profundidade[MAXN];
int nobre_atual, profundidade_alvo, u_atual;

void pegar_filhos_de(int u) {
    if (u != u_atual) filhos.push_back(u);
    
    for (auto v : adj[u]) {
        if (profundidade[v] == profundidade[u] + 1) {
            pegar_filhos_de(v);
        }
    }
}

void determinar_profundidade(int origem, int u, int profundidade_atual) {
    profundidade[u] = profundidade_atual;
    
    for (auto v : adj[u]) {
        if (v != origem) {
            determinar_profundidade(u, v, profundidade_atual + 1);
        }
    }
}

void encontrar_nobre(int u, int profundidade_atual) {
    if (profundidade_atual == profundidade_alvo) {
        nobre_atual = u;
        return;
    }
    
    for (auto v : adj[u]) {
        if (profundidade[v] == profundidade[u] - 1) {
            encontrar_nobre(v, profundidade_atual - 1);
            break;
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 2; i <= N; i++) {
        int x;
        cin >> x;
        
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    
    determinar_profundidade(0, 1, 1);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int operacao;
        cin >> operacao;
        
        if (operacao == 1) {
            int u;
            cin >> u >> profundidade_alvo;
            profundidade_alvo = profundidade[u] - profundidade_alvo;
            encontrar_nobre(u, profundidade[u]);
            cout << nobre_atual << '\n';
        }
        else {
            cin >> u_atual;
            filhos.clear();
            pegar_filhos_de(u_atual);

            int nobre = -1;

            for (auto v : adj[u_atual]) {
                if (profundidade[v] == profundidade[u_atual] - 1) {
                    nobre = v;
                    break;
                }
            }

            adj[u_atual].clear();

            for (auto i : filhos) {
                adj[i].clear();
            }
            
            for (auto i : filhos) {
                adj[i].push_back(u_atual);
                adj[u_atual].push_back(i);
            }

            // A parte que me custou 28 pontos
            // e 2 horas de prova :)
            if (nobre != -1) {
                adj[u_atual].push_back(nobre);
            }
            
            determinar_profundidade(0, 1, 1);
        }
    }
    
    return 0;
}
```
