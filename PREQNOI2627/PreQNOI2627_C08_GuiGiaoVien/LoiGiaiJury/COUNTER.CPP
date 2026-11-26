// COUNTER - loi giai day du: cong x vao chinh dinh p, sau do BFS tu goc 1 va day gia tri xuong con. O(N + Q)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("COUNTER.INP", "r", stdin); freopen("COUNTER.OUT", "w", stdout);
    int n, q; scanf("%d %d", &n, &q);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) { int a, b; scanf("%d %d", &a, &b); g[a].push_back(b); g[b].push_back(a); }
    vector<long long> c(n + 1, 0);
    for (int i = 0; i < q; i++) { int p; long long x; scanf("%d %lld", &p, &x); c[p] += x; }
    vector<int> order; order.reserve(n); vector<int> par(n + 1, 0);
    order.push_back(1); par[1] = -1;
    for (size_t h = 0; h < order.size(); h++) {       // BFS khong de quy
        int u = order[h];
        for (int v : g[u]) if (v != par[u]) { par[v] = u; c[v] += c[u]; order.push_back(v); }
    }
    for (int i = 1; i <= n; i++) printf("%lld%c", c[i], i == n ? '\n' : ' ');
}
