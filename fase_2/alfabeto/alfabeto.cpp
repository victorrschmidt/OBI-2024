#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

set<char> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, N;
    string s, t;
    cin >> K >> N >> s >> t;
    
    for (auto c : s) {
        st.insert(c);
    }
    
    for (auto c : t) {
        if (!st.count(c)) {
            cout << "N\n";
            return 0;
        }
    }
    
    cout << "S\n";
    
    return 0;
}
