/*
 * Bài 3 - BẦU CHỌN (VOTE)
 * Subtask 1 (40%): Q <= 10
 *
 * Ý tưởng: mô phỏng đúng như đề bài. Sau mỗi lần đổi ý, thực hiện lại N lần
 * rút gọn xâu: xâu mới có độ dài bằng 1/3 xâu cũ, ký tự thứ j là ký tự xuất hiện
 * nhiều hơn trong ba ký tự 3j, 3j+1, 3j+2 của xâu cũ.
 * Độ phức tạp: mỗi lần rút gọn toàn bộ tốn 3^N + 3^(N-1) + ... < 1,5 * 3^N,
 * tổng O(Q * 3^N) ~ 8*10^6.
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

    for (int k = 0; k < q; k++) {
        int p;
        cin >> p;
        s[p - 1] = (s[p - 1] == 'A' ? 'B' : 'A');

        string cur = s;
        for (int h = 0; h < n; h++) {
            string nxt(cur.size() / 3, 'B');
            for (size_t j = 0; j < nxt.size(); j++) {
                int cntA = (cur[3 * j] == 'A') + (cur[3 * j + 1] == 'A') + (cur[3 * j + 2] == 'A');
                if (cntA >= 2) nxt[j] = 'A';
            }
            cur = nxt;
        }
        cout << cur << '\n';
    }
    return 0;
}
