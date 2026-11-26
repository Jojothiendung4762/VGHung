/*
 * Bài 4 - KHO CÀ CHUA (TOMATO)
 * Lời giải đầy đủ: N, M <= 1000
 *
 * Mô hình đồ thị: mỗi ô có cà chua là một đỉnh, hai ô kề cạnh là hai đỉnh kề nhau.
 * Ngày quả ở ô u chín = khoảng cách ngắn nhất (số cạnh) từ u tới quả chín ban đầu
 * GẦN NHẤT. Đây là BFS NHIỀU NGUỒN: đưa tất cả các ô chín ban đầu vào hàng đợi
 * với d = 0 rồi loang như BFS thông thường.
 * Đáp án = max d trên mọi ô cà chua; nếu còn ô 0 không được loang tới thì -1.
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
    queue<int> q;
    for (int i = 0; i < n * m; i++) {
        cin >> g[i];
        if (g[i] == 1) { d[i] = 0; q.push(i); }    // mọi quả chín ban đầu là một nguồn
    }
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
