// Bai 3 - STONES - Subtask 3 (20%): a[i] <= 1e5
// BIT tren truc gia tri: bit luu tong dp theo do cao.
// dp[i] = 1 + (tong dp co do cao trong doan [a[i]-K, a[i]+K])
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
const int MAXV = 100000;

ll bit[MAXV + 1];
void add(int i, ll v) { for (; i <= MAXV; i += i & -i) bit[i] = (bit[i] + v) % MOD; }
ll get(int i) {                               // tong tren [1..i]
    ll s = 0;
    for (i = min(i, MAXV); i > 0; i -= i & -i) s += bit[i];
    return s % MOD;
}

int main() {
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    int n; ll k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ll lo = max(1LL, x - k), hi = min((ll)MAXV, x + k);   // chan doan gia tri
        ll d = (1 + get(hi) - get(lo - 1) + MOD) % MOD;
        add(x, d);
        ans = (ans + d) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
