/*
 * Bài 4 - ĐƯỜNG LÀNG (VILLAGE)
 * Subtask 3 (100%): N, Q <= 10^5
 *
 * Ý tưởng: tổ tiên chung gần nhất (LCA).
 *   - Chọn làng 1 làm gốc, BFS tính depth[u] (số cạnh) và d[u] (độ dài từ gốc).
 *   - dist(u, v) = d[u] + d[v] - 2 * d[LCA(u, v)].
 *   - LCA bằng kỹ thuật nhảy nhị phân: up[j][u] là tổ tiên thứ 2^j của u.
 *     Đưa u, v về cùng độ sâu rồi cùng nhảy lên khi tổ tiên còn khác nhau.
 * Dùng BFS (không đệ quy) để tránh tràn ngăn xếp khi cây là đường dài.
 * Độ phức tạp: O((N + Q) log N).
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005, LOG = 17;
int n, q;
vector<pair<int, int>> adj[MAXN];
int up[LOG][MAXN], depth[MAXN];
long long d[MAXN];

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++)
        if (diff >> j & 1) u = up[j][u];
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[j][u] != up[j][v]) {
            u = up[j][u];
            v = up[j][v];
        }
    return up[0][u];
}

int main() {
    freopen("VILLAGE.INP", "r", stdin);
    freopen("VILLAGE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS từ gốc 1
    vector<bool> vis(n + 1, false);
    queue<int> qu;
    qu.push(1); vis[1] = true; up[0][1] = 1;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (auto &e : adj[u]) {
            int v = e.first;
            auto w = e.second;
            if (!vis[v]) {
                vis[v] = true;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                d[v] = d[u] + w;
                qu.push(v);
            }
        }
    }
    for (int j = 1; j < LOG; j++)
        for (int u = 1; u <= n; u++)
            up[j][u] = up[j - 1][up[j - 1][u]];

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << d[u] + d[v] - 2 * d[lca(u, v)] << '\n';
    }
    return 0;
}
