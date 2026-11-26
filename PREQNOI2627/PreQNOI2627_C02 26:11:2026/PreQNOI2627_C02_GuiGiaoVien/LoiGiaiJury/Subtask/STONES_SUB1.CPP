// Bai 3 - STONES - Subtask 1 (40%): N <= 5000, quy hoach dong O(N^2)
// dp[i] = so cach chon ma phien cuoi cung la phien i
//       = 1 + tong dp[j] voi j < i va |a[j] - a[i]| <= K
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

int main() {
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    int n; long long k;
    cin >> n >> k;
    vector<long long> a(n), dp(n);
    for (auto &x : a) cin >> x;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (llabs(a[i] - a[j]) <= k) dp[i] = (dp[i] + dp[j]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
