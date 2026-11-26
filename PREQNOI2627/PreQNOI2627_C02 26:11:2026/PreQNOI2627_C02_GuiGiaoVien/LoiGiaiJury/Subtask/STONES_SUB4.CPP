// Bai 3 - STONES - Subtask 4 (100%): nen so + BIT, O(N log N)
// Nen cac do cao ve chi so 1..m; doan gia tri [a[i]-K, a[i]+K] ung voi
// doan chi so [l+1, r] voi l = lower_bound(a[i]-K), r = upper_bound(a[i]+K)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

int m;
vector<ll> bit;
void add(int i, ll v) { for (; i <= m; i += i & -i) bit[i] = (bit[i] + v) % MOD; }
ll get(int i) { ll s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s % MOD; }

int main() {
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> v(a);                          // nen so
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    m = v.size();
    bit.assign(m + 1, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = lower_bound(v.begin(), v.end(), a[i] - k) - v.begin();   // so gia tri < a[i]-K
        int r = upper_bound(v.begin(), v.end(), a[i] + k) - v.begin();   // so gia tri <= a[i]+K
        ll d = (1 + get(r) - get(l) + MOD) % MOD;
        int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        add(p, d);
        ans = (ans + d) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
