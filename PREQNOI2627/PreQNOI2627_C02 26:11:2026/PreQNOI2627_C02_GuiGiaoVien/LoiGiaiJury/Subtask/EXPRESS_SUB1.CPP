// Bai 4 - EXPRESS - Subtask 1 (20%): K = 0, moi w = 1
// Khong duoc di tau => bo qua canh tau; do thi khong trong so => BFS
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        if (c == 0) { g[u].push_back(v); g[v].push_back(u); }
    }
    vector<int> d(n + 1, -1);
    queue<int> q;
    d[1] = 0; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (d[v] == -1) { d[v] = d[u] + 1; q.push(v); }
    }
    printf("%d\n", d[n]);
    return 0;
}
