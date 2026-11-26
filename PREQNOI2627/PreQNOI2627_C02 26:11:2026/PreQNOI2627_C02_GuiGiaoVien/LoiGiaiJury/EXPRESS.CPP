// Bai 4 - EXPRESS - Subtask 5 (100%): Dijkstra phan tang
// Trang thai (v, j): dang o diem v, da di j luot tau (0 <= j <= K).
//   - canh duong bo: (u, j) -> (v, j)
//   - canh tau:      (u, j) -> (v, j + 1)   neu j < K
// Dap an = min d[N][j] voi j = 0..K. Do phuc tap O((N + M) * K * log).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = LLONG_MAX;

int main() {
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<array<int, 3>>> g(n + 1);       // (v, w, c)
    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        g[u].push_back({v, w, c});
        g[v].push_back({u, w, c});
    }
    int L = k + 1;                                // ma hoa trang thai: id = v * L + j
    vector<ll> d((ll)(n + 1) * L, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[1 * L + 0] = 0; pq.push({0, 1 * L + 0});
    while (!pq.empty()) {
        ll du = pq.top().first; int id = pq.top().second; pq.pop();
        if (du != d[id]) continue;
        int u = id / L, j = id % L;
        for (auto &e : g[u]) {
            int nj = j + e[2];
            if (nj > k) continue;                 // het luot tau
            int nid = e[0] * L + nj;
            if (du + e[1] < d[nid]) { d[nid] = du + e[1]; pq.push({d[nid], nid}); }
        }
    }
    ll ans = INF;
    for (int j = 0; j <= k; j++) ans = min(ans, d[n * L + j]);
    printf("%lld\n", ans == INF ? -1LL : ans);
    return 0;
}
