/*
 * Bài 2 - CỬA HÀNG TRANG SỨC (JEWEL)
 * Subtask 1 (40%): N, M <= 1000
 *
 * Ý tưởng: với mỗi phương án [S, T], duyệt mọi khách hàng.
 * Khách i có mặt trong [L_i, R_i] gặp được cửa hàng mở trong [S, T]
 * khi và chỉ khi hai đoạn có điểm chung:  L_i <= T  và  S <= R_i.
 * Độ phức tạp: O(N * M) <= 10^6.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("JEWEL.INP", "r", stdin);
    freopen("JEWEL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> L(n), R(n);
    vector<long long> C(n);
    for (int i = 0; i < n; i++) cin >> L[i] >> R[i] >> C[i];

    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
        int s, t;
        cin >> s >> t;
        long long sum = 0;
        for (int i = 0; i < n; i++)
            if (L[i] <= t && s <= R[i]) sum += C[i];
        cout << sum << '\n';
    }
    return 0;
}
