/*
 * Bài 4 - KHO CÀ CHUA (TOMATO)
 * Subtask 1 (30%): N, M <= 30
 *
 * Mô phỏng trực tiếp từng ngày: duyệt cả lưới, ô 0 nào có ô kề là quả chín
 * (chín từ TRƯỚC ngày đang xét) thì đánh dấu sẽ chín. Cuối ngày mới cập nhật
 * lưới (tránh "loang" hai bước trong một ngày). Dừng khi một ngày không có quả
 * nào chín thêm.
 * Độ phức tạp: O((N*M) * số ngày) <= O((N*M)^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TOMATO.INP", "r", stdin);
    freopen("TOMATO.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto &row : g) for (auto &c : row) cin >> c;
    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int days = 0;
    while (true) {
        vector<pair<int,int>> ripen;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++) {
                if (g[x][y] != 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 1) {
                        ripen.push_back({x, y});
                        break;
                    }
                }
            }
        if (ripen.empty()) break;
        for (auto [x, y] : ripen) g[x][y] = 1;
        days++;
    }
    for (auto &row : g) for (int c : row) if (c == 0) { days = -1; }
    cout << days << '\n';
    return 0;
}
