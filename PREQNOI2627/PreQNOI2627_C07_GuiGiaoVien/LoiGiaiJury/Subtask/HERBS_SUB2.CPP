// HERBS - Subtask 2: T <= 1e5 -> bai toan cai tui 0/1 kinh dien, QHD theo thoi gian. O(M*T)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("HERBS.INP", "r", stdin); freopen("HERBS.OUT", "w", stdout);
    int T, M; cin >> T >> M;
    vector<long long> f(T + 1, 0);
    for (int i = 0; i < M; i++) {
        long long t, v; cin >> t >> v;
        for (long long j = T; j >= t; j--) f[j] = max(f[j], f[j - t] + v);
    }
    cout << f[T] << "\n";
}
