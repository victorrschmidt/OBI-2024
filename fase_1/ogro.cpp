#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int E, D;
    cin >> E >> D;
    
    cout << (E > D ? E + D : 2 * (D - E)) << nl;
    
    return 0;
}
