#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const double INF = 1e12;

struct f {
    double a, b;
};

vector<f> v(100010);

double x_intersec(int i, int j) {
    if (v[i].a == v[j].a && v[i].b == v[j].b) return INF;
    if (v[i].a == v[j].a) return -INF;
    return (v[j].b - v[i].b) / (v[i].a - v[j].a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double N, L, R;
    cin >> N >> L >> R;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i].a >> v[i].b;
    }
    
    int resp = 0;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double x = x_intersec(i, j);
            
            if (x == INF || (x != -INF && L <= x && x <= R)) resp++;
        }
    }
    
    cout << resp << nl;
    
    return 0;
}
