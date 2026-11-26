/*
 * Bài 4 - KHO CÀ CHUA (TOMATO)
 * Subtask 2 (30%): N, M <= 1000, ban đầu có ĐÚNG MỘT quả chín
 *
 * Chỉ có một nguồn lây: ngày ô u chín = khoảng cách ngắn nhất (số bước đi
 * qua các ô có cà chua) từ quả chín ban đầu tới u. BFS từ một đỉnh nguồn.
 * Đáp án = khoảng cách lớn nhất; còn ô 0 không tới được thì -1.
 * Độ phức tạp: O(N * M).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TOMATO.INP", "r", stdin);
    freopen("TOMATO.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> g(n * m), d(n * m, -1);
    int src = -1;
    for (int i = 0; i < n * m; i++) {
        cin >> g[i];
        if (g[i] == 1) src = i;
    }
    queue<int> q;
    d[src] = 0;
    q.push(src);
    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int x = u / m, y = u % m;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int v = nx * m + ny;
            if (g[v] == 0 && d[v] == -1) { d[v] = d[u] + 1; q.push(v); }
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        if (g[i] == 0 && d[i] == -1) { ans = -1; break; }
        ans = max(ans, d[i]);
    }
    cout << ans << '\n';
    return 0;
}
