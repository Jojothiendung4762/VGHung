// Bai 3 - STONES - Subtask 2 (20%): K = 0
// Chi noi duoc cac phien cung do cao: dp[i] = 1 + tong dp cua cac phien
// cung do cao dung truoc => luu tong theo tung gia tri bang map
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

int main() {
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    int n; long long k, x;
    cin >> n >> k;
    map<long long, long long> sum;           // sum[v] = tong dp cua cac phien do cao v
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        long long d = (1 + sum[x]) % MOD;
        sum[x] = (sum[x] + d) % MOD;
        ans = (ans + d) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
