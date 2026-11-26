/*
 * Bài 3 - HỆ THỐNG ĐÁNH CHẶN (MISSILE)
 * Subtask 2 (30%): N <= 10^5, h_i <= 1000
 *
 * Quy hoạch động theo GIÁ TRỊ độ cao (độ cao nhỏ nên làm chỉ số mảng được):
 *   dn[v] = độ dài dãy con không tăng dài nhất (đã xét) kết thúc bằng độ cao v,
 *   upv[v] = độ dài dãy con tăng ngặt dài nhất (đã xét) kết thúc bằng độ cao v.
 * Với mục tiêu độ cao x:
 *   a = 1 + max{ dn[v]  : v >= x }   -> cập nhật dn[x]  = max(dn[x], a)
 *   b = 1 + max{ upv[v] : v <  x }   -> cập nhật upv[x] = max(upv[x], b)
 * Câu 1 = max dn, câu 2 = max upv (định lý Dilworth).
 * Độ phức tạp: O(N * H) với H = 1000.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MISSILE.INP", "r", stdin);
    freopen("MISSILE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int H = 1000;
    int n;
    cin >> n;
    vector<int> dn(H + 2, 0), upv(H + 2, 0);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int a = 0, b = 0;
        for (int v = x; v <= H; v++) a = max(a, dn[v]);
        for (int v = 1; v < x; v++) b = max(b, upv[v]);
        dn[x] = max(dn[x], a + 1);
        upv[x] = max(upv[x], b + 1);
        ans1 = max(ans1, dn[x]);
        ans2 = max(ans2, upv[x]);
    }
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}
