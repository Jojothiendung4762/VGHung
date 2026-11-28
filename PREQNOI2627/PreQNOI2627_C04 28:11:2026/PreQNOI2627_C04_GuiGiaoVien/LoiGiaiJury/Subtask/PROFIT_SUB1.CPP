/*
 * Bài 2 - LỢI NHUẬN (PROFIT)
 * Subtask 1 (40%): N <= 1000
 *
 * Ý tưởng: duyệt mọi đoạn [l, r]. Với mỗi l, cộng dồn tổng khi tăng r
 * nên không cần vòng lặp thứ ba.
 * Độ phức tạp: O(N^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("PROFIT.INP", "r", stdin);
    freopen("PROFIT.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long cnt = 0;
    for (int l = 0; l < n; l++) {
        long long sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            if (sum == k) cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
