#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, cur = 0;
    cin >> N >> K;
    vector<int> v(101);
    
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v[n]++;
    }
    
    for (int i = 100; i >= 0; i--) {
        if (cur + v[i] >= K) {
            cout << i << nl;
            return 0;
        }
        cur += v[i];
    }
    
    
    return 0;
}
