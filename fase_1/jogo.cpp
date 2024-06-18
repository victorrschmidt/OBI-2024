// 100/100

#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MAX = 60;

int N, Q;
vector<int> adj_i{-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> adj_j{-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> v(MAX);
vector<string> step(MAX);

int alive(int i, int j) {
    int alive = 0;

    for (int k = 0; k < 8; k++) {
        int ni = i + adj_i[k];
        int nj = j + adj_j[k];
        
        if (ni < 0 || N <= ni || nj < 0 || N <= nj) continue;
        if (v[ni][nj] == '1') alive++;
    }
    
    return alive;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v[i] = s;
        step[i] = s;
    }
    
    while (Q--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int n = alive(i, j);
                if (v[i][j] == '0' && n == 3) {
                    step[i][j] = '1';
                }
                if ((v[i][j] == '1' && n < 2) || (v[i][j] == '1' && n > 3)) {
                    step[i][j] = '0';
                }
            }
        }
        for (int i = 0; i < N; i++) {
            v[i] = step[i];
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << v[i] << nl;
    }
    
    return 0;
}
