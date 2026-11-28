/*
 * Bài 3 - TÍN HIỆU (SIGNAL)
 * Subtask 2 (30%): a_i < 2^8 và K < 2^8
 *
 * Ý tưởng: XOR tiền tố + đếm phân phối.
 *   Đặt P[0] = 0, P[i] = a_1 xor ... xor a_i.  XOR đoạn [l, r] = P[r] xor P[l - 1].
 *   Mọi P[i] < 256, nên giữ cnt[v] = số chỉ số j < r có P[j] = v.
 *   Với mỗi r, duyệt 256 giá trị v, cộng cnt[v] nếu (P[r] xor v) >= K.
 * Độ phức tạp: O(N * 256).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    const int V = 256;
    long long cnt[V] = {0};
    cnt[0] = 1;            // P[0] = 0
    int p = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p ^= x;
        for (int v = 0; v < V; v++)
            if ((p ^ v) >= k) ans += cnt[v];
        cnt[p]++;
    }

    cout << ans << '\n';
    return 0;
}
