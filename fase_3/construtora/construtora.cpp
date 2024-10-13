#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int v[110];
int N;

bool all_equal() {
    for (int i = 1; i < N; i++) {
        if (v[i] != v[0]) return 0;
    }
    return 1;
}

int v_min() {
    int retval = 100;    
    
    for (int i = 0; i < N; i++) {
        retval = min(retval, v[i]);
    }
    
    return retval;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int resp = 0;
    
    while (!all_equal()) {
        int m = v_min();
        
        for (int i = 0; i < N; i++) {
            if (v[i] != m) continue;
            
            resp++;
            v[i]++;
            for (int j = i + 1; j < N; j++) {
                if (v[j] == m) v[j]++;
                else break;
            }
            
            break;
        }
    }
    
    cout << resp << nl;
    
    return 0;
}
