/*
 * Bài 2 - CỬA HÀNG TRANG SỨC (JEWEL)
 * Subtask 2 (30%): S_j = T_j với mọi j (cửa hàng chỉ mở tại một thời điểm)
 *
 * Ý tưởng: cần tính f[t] = tổng C_i của các khách có L_i <= t <= R_i.
 * Dùng mảng hiệu (difference array):
 *   d[L_i] += C_i,  d[R_i + 1] -= C_i,  rồi f = tổng tiền tố của d.
 * Mỗi phương án trả lời f[S_j] trong O(1).
 * Độ phức tạp: O(N + M + MAXT).
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1000000;
long long d[MAXT + 2];

int main() {
    freopen("JEWEL.INP", "r", stdin);
    freopen("JEWEL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        long long c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r + 1] -= c;
    }
    for (int t = 1; t <= MAXT; t++) d[t] += d[t - 1];

    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
        int s, t;
        cin >> s >> t;
        cout << d[s] << '\n';
    }
    return 0;
}
