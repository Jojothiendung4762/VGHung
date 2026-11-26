/*
 * Bài 3 - BẦU CHỌN (VOTE)
 * Subtask 2 (30%): N <= 6 (tối đa 729 học sinh), Q <= 2*10^5
 *
 * Ý tưởng: vẫn mô phỏng lại toàn bộ sau mỗi lần đổi ý, nhưng cài đặt gọn:
 * dùng một mảng số nguyên b (1 = 'A', 0 = 'B') và rút gọn NGAY TRÊN mảng tạm,
 * không tạo xâu mới -> mỗi truy vấn tốn khoảng 1,5 * 3^N <= 1100 phép tính.
 * Độ phức tạp: O(Q * 3^N) ~ 2,2*10^8 phép tính đơn giản.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("VOTE.INP", "r", stdin);
    freopen("VOTE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;
    int len = s.size();
    vector<int> a(len), b(len);
    for (int i = 0; i < len; i++) a[i] = (s[i] == 'A');

    string out;
    for (int k = 0; k < q; k++) {
        int p;
        cin >> p;
        a[p - 1] ^= 1;
        for (int i = 0; i < len; i++) b[i] = a[i];
        int sz = len;
        while (sz > 1) {
            sz /= 3;
            for (int j = 0; j < sz; j++) b[j] = (b[3 * j] + b[3 * j + 1] + b[3 * j + 2] >= 2);
        }
        out += (b[0] ? 'A' : 'B');
        out += '\n';
    }
    cout << out;
    return 0;
}
