// BUILD - Subtask 2: N <= 1000, M <= 1e4 -> lap cap nhat (kieu Bellman-Ford) toi khi on dinh. O(N*M)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BUILD.INP", "r", stdin); freopen("BUILD.OUT", "w", stdout);
    int n, m; cin >> n >> m;
    vector<long long> d(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) { cin >> d[i]; f[i] = d[i]; }
    vector<pair<int,int>> e(m);
    for (auto &p : e) cin >> p.first >> p.second;
    int w; cin >> w;
    for (int it = 0; it < n; it++) {
        bool ch = false;
        for (auto &pr : e) { int x = pr.first, y = pr.second; if (f[x] + d[y] > f[y]) { f[y] = f[x] + d[y]; ch = true; } }
        if (!ch) break;
    }
    cout << f[w] << "\n";
}
