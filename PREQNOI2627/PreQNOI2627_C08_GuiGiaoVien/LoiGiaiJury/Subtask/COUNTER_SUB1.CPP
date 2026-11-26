// COUNTER - Subtask 1: N, Q <= 2000 -> moi thao tac duyet (DFS) ca cay con cua p. O(N*Q)
#include <bits/stdc++.h>
using namespace std;
int n, q; vector<vector<int>> g; vector<int> par; vector<long long> c;
void add(int u, long long x) {
    c[u] += x;
    for (int v : g[u]) if (v != par[u]) add(v, x);
}
void root(int u, int p) { par[u] = p; for (int v : g[u]) if (v != p) root(v, u); }
int main() {
    freopen("COUNTER.INP", "r", stdin); freopen("COUNTER.OUT", "w", stdout);
    cin >> n >> q; g.assign(n + 1, {}); par.assign(n + 1, 0); c.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) { int a, b; cin >> a >> b; g[a].push_back(b); g[b].push_back(a); }
    root(1, 0);
    for (int i = 0; i < q; i++) { int p; long long x; cin >> p >> x; add(p, x); }
    for (int i = 1; i <= n; i++) cout << c[i] << (i == n ? '\n' : ' ');
}
