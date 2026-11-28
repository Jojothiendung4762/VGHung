/*
 * Bài 4 - ĐƯỜNG LÀNG (VILLAGE)
 * Subtask 1 (30%): N, Q <= 1000
 *
 * Ý tưởng: với mỗi câu hỏi, duyệt DFS/BFS từ u để tính khoảng cách tới mọi
 * làng (trên cây đường đi giữa hai đỉnh là duy nhất), rồi lấy dist[v].
 * Độ phức tạp: O(N * Q).
 */
#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<pair<int, long long>> adj[100005];
long long dist[100005];

void bfs(int s) {
    fill(dist + 1, dist + n + 1, -1);
    queue<int> qu;
    dist[s] = 0;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (auto &e : adj[u]) {
            int v = e.first;
            auto w = e.second;
            if (dist[v] < 0) {
                dist[v] = dist[u] + w;
                qu.push(v);
            }
        }
    }
}

int main() {
    freopen("VILLAGE.INP", "r", stdin);
    freopen("VILLAGE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        bfs(u);
        cout << dist[v] << '\n';
    }
    return 0;
}
