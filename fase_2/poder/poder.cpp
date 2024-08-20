#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<ll>> m(N, vector<ll>(M));
    vector<vector<ll>> resp(N, vector<ll>(M));
    
    for (auto& i : m) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            vector<vector<bool>> vis(N, vector<bool>(M));
            priority_queue<vector<ll>> pq;  // {v, i, j}
            vis[i][j] = 1;
            pq.push({0, i, j});
            ll cur = m[i][j];
            
            while (!pq.empty()) {
                ll v = -pq.top()[0];
                ll i = pq.top()[1];
                ll j = pq.top()[2];
                pq.pop();
                
                if (cur < v) break;
                cur += v;
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    
                    if (0 <= min(ni, nj) && ni < N && nj < M && !vis[ni][nj]) {
                        vis[ni][nj] = 1;
                        pq.push({-m[ni][nj], ni, nj});
                    }
                }
            }
            
            resp[i][j] = cur;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << resp[i][j] << " \n"[j == M - 1];
        }
    }

    return 0;
}
