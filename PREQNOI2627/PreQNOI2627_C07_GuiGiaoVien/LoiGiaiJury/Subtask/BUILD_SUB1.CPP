// BUILD - Subtask 1: moi quy tac X -> Y deu co X < Y -> xet cac cong trinh theo thu tu chi so. O(N + M)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BUILD.INP", "r", stdin); freopen("BUILD.OUT", "w", stdout);
    int n, m; cin >> n >> m;
    vector<long long> d(n + 1), start(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> d[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) { int x, y; cin >> x >> y; g[x].push_back(y); }
    int w; cin >> w;
    for (int u = 1; u <= n; u++)
        for (int v : g[u]) start[v] = max(start[v], start[u] + d[u]);
    cout << start[w] + d[w] << "\n";
}
