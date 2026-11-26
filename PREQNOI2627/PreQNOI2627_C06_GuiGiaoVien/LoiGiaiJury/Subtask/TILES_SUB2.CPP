/*
 * Bài 1 - LÁT SÂN (TILES)
 * Subtask 2 (100%): N, M, A <= 10^9
 *
 * Ý tưởng: theo chiều dài N cần ceil(N/A) hàng gạch, theo chiều rộng M cần
 * ceil(M/A) cột gạch. Hai chiều độc lập nên đáp án là tích của hai số này.
 *   ceil(x/a) = (x + a - 1) / a   (chia nguyên, không dùng số thực)
 * Lưu ý: đáp án tới 10^18, phải dùng long long cho cả phép nhân.
 * Độ phức tạp: O(1).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TILES.INP", "r", stdin);
    freopen("TILES.OUT", "w", stdout);
    long long n, m, a;
    cin >> n >> m >> a;
    long long rows = (n + a - 1) / a;
    long long cols = (m + a - 1) / a;
    cout << rows * cols << '\n';
    return 0;
}
