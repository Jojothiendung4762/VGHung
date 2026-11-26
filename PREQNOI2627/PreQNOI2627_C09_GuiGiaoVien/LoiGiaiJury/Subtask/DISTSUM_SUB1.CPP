/*
 * Bai 4 - DISTSUM, Subtask 1 (N <= 2000)
 * Y tuong: BFS tu tung dinh, cong khoang cach toi moi dinh khac.
 * Do phuc tap: O(N^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DISTSUM.INP", "r", stdin);
    freopen("DISTSUM.OUT", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1);
    for (int s = 1; s <= n; s++) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        long long total = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            total += dist[u];
            for (int v : adj[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }
        printf("%lld%c", total, s == n ? '\n' : ' ');
    }
    return 0;
}
