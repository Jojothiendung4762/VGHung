// Bai 4 - EXPRESS - Subtask 3 (20%): N <= 100
// D = Floyd tren duong bo. f[v] = thoi gian ngan nhat tu 1 toi v, da dung <= j luot tau.
// Moi luot tau them: f'[v] = min(f[v], f[x] + w(x,y) + D[y][v]) voi moi canh tau (x,y).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

int main() {
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<ll>> D(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) D[i][i] = 0;
    vector<array<ll, 3>> boat;                 // canh tau (x, y, w) luu ca hai chieu
    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        if (c == 0) { D[u][v] = min(D[u][v], (ll)w); D[v][u] = min(D[v][u], (ll)w); }
        else { boat.push_back({u, v, w}); boat.push_back({v, u, w}); }
    }
    for (int t = 1; t <= n; t++)
        for (int i = 1; i <= n; i++) if (D[i][t] < INF)
            for (int j = 1; j <= n; j++) if (D[t][j] < INF)
                D[i][j] = min(D[i][j], D[i][t] + D[t][j]);
    vector<ll> f(n + 1);
    for (int v = 1; v <= n; v++) f[v] = D[1][v];
    for (int j = 1; j <= k; j++) {
        vector<ll> g = f;
        for (auto &b : boat) if (f[b[0]] < INF)
            for (int v = 1; v <= n; v++) if (D[b[1]][v] < INF)
                g[v] = min(g[v], f[b[0]] + b[2] + D[b[1]][v]);
        f = g;
    }
    printf("%lld\n", f[n] >= INF ? -1LL : f[n]);
    return 0;
}
