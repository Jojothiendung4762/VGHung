/*
 * Bài 2 - LỢI NHUẬN (PROFIT)
 * Subtask 2 (30%): mọi a_i >= 1 và K >= 1
 *
 * Ý tưởng: hai con trỏ.
 *   Vì mọi a_i dương nên khi r tăng, tổng đoạn [l, r] tăng; khi l tăng, tổng giảm.
 *   Với mỗi r, dịch l sang phải chừng nào tổng còn > K.
 *   Khi dừng, tổng <= K; nếu tổng = K thì đó là đoạn duy nhất kết thúc tại r.
 * Độ phức tạp: O(N).
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

    long long cnt = 0, sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > k) sum -= a[l++];
        if (sum == k) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
