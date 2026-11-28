/*
 * Bài 2 - LỢI NHUẬN (PROFIT)
 * Subtask 3 (100%): N <= 2 * 10^5, a_i có thể âm
 *
 * Ý tưởng: tổng tiền tố.
 *   Đặt S[0] = 0, S[i] = a_1 + ... + a_i.
 *   Tổng đoạn [l, r] = S[r] - S[l - 1] = K  <=>  S[l - 1] = S[r] - K.
 *   Duyệt r tăng dần, đếm số chỉ số j < r có S[j] = S[r] - K.
 *   Dùng mảng tiền tố đã sắp xếp + tìm kiếm nhị phân (hoặc map).
 * Kết quả có thể tới N(N+1)/2 ~ 2 * 10^10, phải dùng long long.
 * Độ phức tạp: O(N log N).
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

    map<long long, int> seen;   // seen[x] = số chỉ số j đã duyệt có S[j] = x
    seen[0] = 1;                // S[0] = 0
    long long s = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s += x;
        auto it = seen.find(s - k);
        if (it != seen.end()) cnt += it->second;
        seen[s]++;
    }

    cout << cnt << '\n';
    return 0;
}
