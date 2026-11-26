// Bai 4 - EXPRESS - Subtask 4 (20%): K = 1
// Dijkstra tren duong bo tu 1 (d1) va tu N (dn).
// Dap an = min( d1[N], d1[x] + w + dn[y] ) voi moi canh tau (x,y) xet ca hai chieu.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = LLONG_MAX / 4;
int n, m, k;
vector<vector<pair<int, int>>> g;

vector<ll> dijkstra(int s) {
    vector<ll> d(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        ll du = pq.top().first; int u = pq.top().second; pq.pop();
        if (du != d[u]) continue;
        for (auto &e : g[u])
            if (du + e.second < d[e.first]) { d[e.first] = du + e.second; pq.push({d[e.first], e.first}); }
    }
    return d;
}

int main() {
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    g.assign(n + 1, {});
    vector<array<int, 3>> boat;
    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        if (c == 0) { g[u].push_back({v, w}); g[v].push_back({u, w}); }
        else boat.push_back({u, v, w});
    }
    vector<ll> d1 = dijkstra(1), dn = dijkstra(n);
    ll ans = d1[n];
    if (k >= 1)
        for (auto &b : boat) {
            ans = min(ans, d1[b[0]] + b[2] + dn[b[1]]);
            ans = min(ans, d1[b[1]] + b[2] + dn[b[0]]);
        }
    printf("%lld\n", ans >= INF ? -1LL : ans);
    return 0;
}
