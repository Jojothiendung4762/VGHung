// HERBS - Subtask 3: v_i <= 1000 -> doi vai tro: g[s] = thoi gian it nhat de hai duoc tong gia tri dung bang s.
// Dap an = s lon nhat co g[s] <= T. O(M * tong gia tri) <= 100 * 1e5
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("HERBS.INP", "r", stdin); freopen("HERBS.OUT", "w", stdout);
    long long T; int M; cin >> T >> M;
    vector<long long> t(M), v(M); long long S = 0;
    for (int i = 0; i < M; i++) { cin >> t[i] >> v[i]; S += v[i]; }
    const long long INF = LLONG_MAX / 4;
    vector<long long> g(S + 1, INF); g[0] = 0;
    for (int i = 0; i < M; i++)
        for (long long s = S; s >= v[i]; s--) g[s] = min(g[s], g[s - v[i]] + t[i]);
    long long ans = 0;
    for (long long s = S; s >= 0; s--) if (g[s] <= T) { ans = s; break; }
    cout << ans << "\n";
}
