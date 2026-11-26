// Bai 1 - LANTERN - Subtask 1 (60%): duyet O(N)
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

int main() {
    freopen("LANTERN.INP", "r", stdin);
    freopen("LANTERN.OUT", "w", stdout);
    long long N, A, B;
    cin >> N >> A >> B;
    long long ans = 0;
    for (long long i = 1; i <= N; i++) {
        if (i % A == 0 || i % B == 0) ans += 2 * i;   // den long lon: 2i bong
        else ans += i;                                 // den thuong: i bong
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
