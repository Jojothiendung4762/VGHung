/*
 * Bài 2 - TƯỚI CÂY (WATER)
 * Subtask 2 (70%): N, M <= 10^5, Q <= 10
 *
 * Ý tưởng: MẢNG KHÁC BIỆT.
 *   Tưới x lít cho đoạn [l, r]  <=>  diff[l] += x, diff[r + 1] -= x.
 *   Sau M lần tưới: water[i] = diff[1] + diff[2] + ... + diff[i].
 *   Mỗi câu hỏi vẫn đếm trực tiếp trên N cây.
 * Độ phức tạp: O(N + M + N * Q).
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

    vector<long long> diff(n + 2, 0);
    for (int j = 0; j < m; j++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }

    vector<long long> water(n + 1, 0);
    for (int i = 1; i <= n; i++) water[i] = water[i - 1] + diff[i];

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
