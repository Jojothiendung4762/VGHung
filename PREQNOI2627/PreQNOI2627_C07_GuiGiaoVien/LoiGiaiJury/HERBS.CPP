// HERBS - loi giai day du: tuy du lieu ma chon cach giai
//   T <= 1e5            : QHD theo thoi gian  f[j] = gia tri lon nhat voi tong thoi gian <= j  O(M*T)
//   tong gia tri <= 1e5 : QHD theo gia tri    g[v] = thoi gian it nhat de dat dung gia tri v  O(M*sumV)
//   con lai (M <= 20)   : duyet moi tap con   O(2^M * M)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("HERBS.INP", "r", stdin); freopen("HERBS.OUT", "w", stdout);
    long long T; int M; cin >> T >> M;
    vector<long long> t(M), v(M);
    long long sumV = 0;
    for (int i = 0; i < M; i++) { cin >> t[i] >> v[i]; sumV += v[i]; }
    long long ans = 0;
    if (T <= 100000) {
        vector<long long> f(T + 1, 0);
        for (int i = 0; i < M; i++)
            for (long long j = T; j >= t[i]; j--) f[j] = max(f[j], f[j - t[i]] + v[i]);
        ans = f[T];
    } else if (sumV <= 100000) {
        const long long INF = LLONG_MAX / 4;
        vector<long long> g(sumV + 1, INF); g[0] = 0;
        for (int i = 0; i < M; i++)
            for (long long s = sumV; s >= v[i]; s--)
                if (g[s - v[i]] + t[i] < g[s]) g[s] = g[s - v[i]] + t[i];
        for (long long s = sumV; s >= 0; s--) if (g[s] <= T) { ans = s; break; }
    } else {
        for (int mask = 0; mask < (1 << M); mask++) {
            long long st = 0, sv = 0;
            for (int i = 0; i < M; i++) if (mask >> i & 1) { st += t[i]; sv += v[i]; }
            if (st <= T) ans = max(ans, sv);
        }
    }
    cout << ans << "\n";
}
