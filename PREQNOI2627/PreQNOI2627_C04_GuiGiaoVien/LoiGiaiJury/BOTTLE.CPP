/*
 * Bài 1 - ĐỔI VỎ CHAI (BOTTLE)
 * Subtask 2 (100%): N, K <= 10^18
 *
 * Ý tưởng: đổi theo từng "đợt" thay vì từng chai.
 *   - Có e vỏ thì một đợt đổi được q = e / K chai mới.
 *   - Sau đợt đó còn e % K vỏ thừa, uống q chai mới được thêm q vỏ:
 *         e = e % K + q.
 * Mỗi đợt số vỏ giảm ít nhất một nửa (khi K >= 2) nên chỉ có O(log N) đợt.
 * (Có thể dùng công thức: tổng = N + (N - 1) / (K - 1).)
 * Lưu ý: kết quả có thể tới 2 * 10^18, phải dùng long long.
 * Độ phức tạp: O(log N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("BOTTLE.INP", "r", stdin);
    freopen("BOTTLE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long drunk = n;
    long long empty = n;

    while (empty >= k) {
        long long q = empty / k;   // số chai đổi được trong đợt này
        drunk += q;
        empty = empty % k + q;
    }

    cout << drunk << '\n' << empty << '\n';
    return 0;
}
