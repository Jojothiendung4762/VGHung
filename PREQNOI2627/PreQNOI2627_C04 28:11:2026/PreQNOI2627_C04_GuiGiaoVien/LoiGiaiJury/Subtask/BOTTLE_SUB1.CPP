/*
 * Bài 1 - ĐỔI VỎ CHAI (BOTTLE)
 * Subtask 1 (60%): N, K <= 10^6
 *
 * Ý tưởng: mô phỏng trực tiếp từng lần đổi.
 *   - Uống hết N chai ban đầu, được N vỏ.
 *   - Còn ít nhất K vỏ thì đổi lấy 1 chai, uống xong lại được thêm 1 vỏ.
 * Mỗi lần đổi số vỏ giảm đúng K - 1 nên số lần đổi không quá N / (K - 1) <= 10^6.
 * Độ phức tạp: O(N / (K - 1)).
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

    long long drunk = n;   // số chai đã uống
    long long empty = n;   // số vỏ đang có

    while (empty >= k) {
        empty -= k;        // đưa K vỏ cho cửa hàng
        drunk++;           // nhận 1 chai mới và uống
        empty++;           // được thêm 1 vỏ
    }

    cout << drunk << '\n' << empty << '\n';
    return 0;
}
