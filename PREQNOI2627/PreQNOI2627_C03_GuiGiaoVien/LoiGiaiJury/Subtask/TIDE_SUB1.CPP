/*
 * Bài 4 - THỦY TRIỀU (TIDE)
 * Subtask 1 (20%): N, M, Q <= 1000
 *
 * Ý tưởng: với mỗi câu hỏi (u, t), BFS từ đảo u, chỉ đi qua lối đi chưa ngập (h > t).
 *          Số đảo đến được = số đỉnh được thăm.
 * Độ phức tạp: O(Q * (N + M)).
 */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long h;
};

int main() {
    freopen("TIDE.INP", "r", stdin);
    freopen("TIDE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long h;
        cin >> u >> v >> h;
        adj[u].push_back({v, h});
        adj[v].push_back({u, h});
    }

    vector<bool> visited(n + 1);
    while (q--) {
        int start;
        long long t;
        cin >> start >> t;

        fill(visited.begin(), visited.end(), false);
        queue<int> bfs;
        bfs.push(start);
        visited[start] = true;
        int reached = 0;
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            reached++;
            for (const Edge &e : adj[u])
                if (e.h > t && !visited[e.to]) {     // lối đi chưa ngập
                    visited[e.to] = true;
                    bfs.push(e.to);
                }
        }
        cout << reached << '\n';
    }
    return 0;
}
