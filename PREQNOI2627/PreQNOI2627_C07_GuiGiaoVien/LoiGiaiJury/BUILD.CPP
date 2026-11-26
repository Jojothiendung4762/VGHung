// BUILD - loi giai day du: sap xep topo (Kahn) + QHD tren DAG. O(N + M)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BUILD.INP", "r", stdin); freopen("BUILD.OUT", "w", stdout);
    int n, m; scanf("%d %d", &n, &m);
    vector<long long> d(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
    vector<vector<int>> g(n + 1); vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) { int x, y; scanf("%d %d", &x, &y); g[x].push_back(y); indeg[y]++; }
    int w; scanf("%d", &w);
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<long long> start(n + 1, 0);       // start[u] = thoi diem som nhat bat dau xay u
    while (!q.empty()) {
        int u = q.front(); q.pop();
        f[u] = start[u] + d[u];               // thoi diem xay xong u
        for (int v : g[u]) {
            start[v] = max(start[v], f[u]);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    printf("%lld\n", f[w]);
}
