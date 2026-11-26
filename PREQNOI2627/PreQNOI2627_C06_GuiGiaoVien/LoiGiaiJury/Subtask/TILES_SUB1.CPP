/*
 * Bài 1 - LÁT SÂN (TILES)
 * Subtask 1 (60%): N, M <= 1000
 *
 * Ý tưởng: đặt lần lượt từng hàng gạch theo chiều dài cho đến khi phủ kín N mét,
 * đếm số hàng; làm tương tự theo chiều rộng. Số viên = số hàng * số cột.
 * Độ phức tạp: O(N + M) (khi A = 1).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TILES.INP", "r", stdin);
    freopen("TILES.OUT", "w", stdout);
    int n, m, a;               // với N, M <= 1000, đáp án <= 10^6, kiểu int là đủ
    cin >> n >> m >> a;
    int rows = 0, covered = 0;
    while (covered < n) { covered += a; rows++; }
    int cols = 0;
    covered = 0;
    while (covered < m) { covered += a; cols++; }
    cout << rows * cols << '\n';
    return 0;
}
