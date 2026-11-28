/*
 * Bài 3 - TÍN HIỆU (SIGNAL)
 * Subtask 1 (40%): N <= 3000
 *
 * Ý tưởng: duyệt mọi đoạn [l, r], tính XOR cộng dồn khi tăng r.
 * Độ phức tạp: O(N^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long cnt = 0;
    for (int l = 0; l < n; l++) {
        long long x = 0;
        for (int r = l; r < n; r++) {
            x ^= a[r];
            if (x >= k) cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
