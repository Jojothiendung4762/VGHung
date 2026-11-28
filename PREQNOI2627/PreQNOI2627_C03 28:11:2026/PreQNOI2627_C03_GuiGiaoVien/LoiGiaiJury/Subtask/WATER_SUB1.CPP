/*
 * Bài 2 - TƯỚI CÂY (WATER)
 * Subtask 1 (40%): N, M, Q <= 1000
 *
 * Ý tưởng: mô phỏng đúng đề bài.
 *   - Mỗi lần tưới: cộng x vào từng cây trong đoạn [l, r].
 *   - Mỗi câu hỏi: đếm số cây có lượng nước >= T.
 * Độ phức tạp: O(N * M + N * Q).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("WATER.INP", "r", stdin);
    freopen("WATER.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> water(n + 1, 0);          // water[i]: lượng nước của cây i
    for (int j = 0; j < m; j++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; i++) water[i] += x;
    }

    while (q--) {
        long long t;
        cin >> t;
        int count = 0;
        for (int i = 1; i <= n; i++)
            if (water[i] >= t) count++;
        cout << count << '\n';
    }
    return 0;
}
