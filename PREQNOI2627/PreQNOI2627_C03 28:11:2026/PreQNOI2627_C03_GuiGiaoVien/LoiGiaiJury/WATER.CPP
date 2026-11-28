/*
 * Bài 2 - TƯỚI CÂY (WATER)
 * Subtask 3 (100%): N, M, Q <= 2 * 10^5
 *
 * Ý tưởng:
 *   1) Mảng khác biệt để tính lượng nước của từng cây trong O(N + M).
 *   2) Sắp xếp lượng nước tăng dần.
 *   3) Với câu hỏi T: vị trí đầu tiên có giá trị >= T là lower_bound(T);
 *      số cây thỏa mãn = N - (vị trí đó).
 * Độ phức tạp: O(N log N + M + Q log N).
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

    // Bước 1: mảng khác biệt
    vector<long long> diff(n + 2, 0);
    for (int j = 0; j < m; j++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }

    vector<long long> water(n);                  // water[0..n-1]: lượng nước cây 1..n
    long long current = 0;
    for (int i = 1; i <= n; i++) {
        current += diff[i];
        water[i - 1] = current;
    }

    // Bước 2: sắp xếp tăng dần
    sort(water.begin(), water.end());

    // Bước 3: trả lời câu hỏi bằng tìm kiếm nhị phân
    while (q--) {
        long long t;
        cin >> t;
        int firstGood = lower_bound(water.begin(), water.end(), t) - water.begin();
        cout << n - firstGood << '\n';
    }
    return 0;
}
