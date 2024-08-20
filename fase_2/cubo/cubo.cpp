#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, m, a, b, c, d;
    cin >> N;
    
    m = max(0, N - 2);
    
    d = 8;
    c = 12 * m;
    b = m * m * 6;
    a = max(0, N * N * N - b - c - d);
    
    printf("%d\n%d\n%d\n%d\n", a, b, c, d);

    return 0;
}
