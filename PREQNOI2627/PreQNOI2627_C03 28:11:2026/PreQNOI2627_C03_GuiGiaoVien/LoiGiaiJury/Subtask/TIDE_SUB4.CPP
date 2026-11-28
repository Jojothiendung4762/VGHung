/*
 * Bài 4 - THỦY TRIỀU (TIDE)
 * Subtask 4 (20%): các đảo nằm trên một đường thẳng, lối đi thứ i nối đảo i và đảo i + 1
 *
 * Ý tưởng: gọi h[i] là độ cao lối đi giữa đảo i và i + 1.
 *   Từ đảo u đi sang trái tới đảo L được  <=>  min(h[L], ..., h[u-1]) > t.
 *   Từ đảo u đi sang phải tới đảo R được  <=>  min(h[u], ..., h[R-1]) > t.
 *   Dùng bảng thưa (sparse table) để lấy min trên đoạn trong O(1),
 *   rồi tìm kiếm nhị phân L nhỏ nhất và R lớn nhất. Đáp án = R - L + 1.
 * Độ phức tạp: O(N log N + Q log N).
 */
#include <bits/stdc++.h>
using namespace std;

struct SparseTableMin {
    vector<vector<long long>> table;
    vector<int> lg;
    SparseTableMin(const vector<long long> &a) {
        int n = a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        table.assign(lg[n] + 1, a);
        for (int k = 1; k <= lg[n]; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }
    long long query(int l, int r) {                   // min a[l..r], l <= r
        int k = lg[r - l + 1];
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};

int main() {
    freopen("TIDE.INP", "r", stdin);
    freopen("TIDE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> h(max(n, 2), LLONG_MAX);         // h[i]: lối đi giữa đảo i và i + 1
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        h[min(u, v)] = w;
    }
    SparseTableMin st(h);

    while (q--) {
        int u;
        long long t;
        cin >> u >> t;

        int lo = 1, hi = u;                           // L nhỏ nhất với min(h[L..u-1]) > t
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (st.query(mid, u - 1) > t) hi = mid;
            else lo = mid + 1;
        }
        int L = lo;

        lo = u, hi = n;                               // R lớn nhất với min(h[u..R-1]) > t
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (st.query(u, mid - 1) > t) lo = mid;
            else hi = mid - 1;
        }
        int R = lo;

        cout << R - L + 1 << '\n';
    }
    return 0;
}
