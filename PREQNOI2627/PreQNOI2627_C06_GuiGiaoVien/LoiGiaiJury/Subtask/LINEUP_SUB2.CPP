/*
 * Bài 2 - XẾP HÀNG (LINEUP)
 * Subtask 2 (30%): hàng có dạng L...LR...R (a bạn nhìn 'L' đứng trước, b bạn nhìn 'R' đứng sau)
 *
 * Nhận xét: chọn lớp trưởng là bạn thứ i.
 *   - i nằm trong nhóm 'L' (i <= a): phải quay (i-1) bạn 'L' bên trái và cả b bạn 'R'.
 *     Tốt nhất là i = 1: chi phí b.
 *   - i nằm trong nhóm 'R' (i > a): phải quay cả a bạn 'L' và (N-i) bạn 'R' bên phải.
 *     Tốt nhất là i = N: chi phí a.
 * Đáp án = min(a, b). Chỉ cần đếm số chữ 'L' và 'R'.
 * Độ phức tạp: O(N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("LINEUP.INP", "r", stdin);
    freopen("LINEUP.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    long long a = count(s.begin(), s.end(), 'L');
    long long b = n - a;
    cout << min(a, b) << '\n';
    return 0;
}
