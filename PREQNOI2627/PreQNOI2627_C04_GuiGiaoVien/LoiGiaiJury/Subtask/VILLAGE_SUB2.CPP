/*
 * Bài 4 - ĐƯỜNG LÀNG (VILLAGE)
 * Subtask 2 (30%): con đường thứ i nối làng i với làng i + 1
 *
 * Ý tưởng: các làng nằm trên một đường thẳng. Đặt pos[1] = 0,
 * pos[i + 1] = pos[i] + w_i (tổng tiền tố độ dài đường).
 * Khoảng cách giữa u và v là |pos[u] - pos[v]|.
 * Độ phức tạp: O(N + Q).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("VILLAGE.INP", "r", stdin);
    freopen("VILLAGE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> pos(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;   // u = i, v = i + 1
        pos[i + 1] = pos[i] + w;
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << llabs(pos[u] - pos[v]) << '\n';
    }
    return 0;
}
