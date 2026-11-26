// HERBS - Subtask 1: M <= 20 -> duyet moi tap con cay thuoc. O(2^M * M)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("HERBS.INP", "r", stdin); freopen("HERBS.OUT", "w", stdout);
    long long T; int M; cin >> T >> M;
    vector<long long> t(M), v(M);
    for (int i = 0; i < M; i++) cin >> t[i] >> v[i];
    long long ans = 0;
    for (int mask = 0; mask < (1 << M); mask++) {
        long long st = 0, sv = 0;
        for (int i = 0; i < M; i++) if (mask >> i & 1) { st += t[i]; sv += v[i]; }
        if (st <= T) ans = max(ans, sv);
    }
    cout << ans << "\n";
}
