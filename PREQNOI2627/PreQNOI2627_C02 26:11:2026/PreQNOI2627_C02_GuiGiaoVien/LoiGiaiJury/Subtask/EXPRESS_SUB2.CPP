// Bai 4 - EXPRESS - Subtask 2 (20%): K = 0
// Bo qua canh tau, Dijkstra tren cac duong bo
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
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        if (c == 0) { g[u].push_back({v, w}); g[v].push_back({u, w}); }
    }
    vector<ll> d(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[1] = 0; pq.push({0, 1});
    while (!pq.empty()) {
        ll du = pq.top().first; int u = pq.top().second; pq.pop();
        if (du != d[u]) continue;
        for (auto &e : g[u])
            if (du + e.second < d[e.first]) { d[e.first] = du + e.second; pq.push({d[e.first], e.first}); }
    }
    printf("%lld\n", d[n] == INF ? -1LL : d[n]);
    return 0;
}
