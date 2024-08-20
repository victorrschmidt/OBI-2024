#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MAX = (int) 1e6 + 10;

int lin[MAX], col[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, P;
    cin >> N >> M >> P;
    
    for (int i = 1; i <= max(N, M); i++) {
        if (i <= N) lin[i] = i;
        if (i <= M) col[i] = i;
    }
    
    for (int i = 0; i < P; i++) {
        char mov;
        int a, b;
        cin >> mov >> a >> b;
        
        if (mov == 'C') swap(col[a], col[b]);
        else swap(lin[a], lin[b]);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << (lin[i] - 1) * M + col[j] << ' ';
        }
        cout << nl;
    }

    return 0;
}
