// Bai 1 - LANTERN - Subtask 2 (100%): cong thuc O(1)
// Dap an = T(N) + S(A) + S(B) - S(BCNN(A,B))   (mod 1e9+7)
//   T(m) = 1 + 2 + ... + m = m(m+1)/2
//   S(d) = tong cac boi cua d trong [1..N] = d * T(N/d)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll N, A, B;

ll gcdll(ll a, ll b) { while (b) { ll t = a % b; a = b; b = t; } return a; }

// T(m) mod MOD; chia 2 cho so chan TRUOC khi lay mod va nhan (tranh tran so)
ll T(ll m) {
    ll x = m, y = m + 1;
    if (x % 2 == 0) x /= 2; else y /= 2;
    return (x % MOD) * (y % MOD) % MOD;
}

ll S(ll d) {
    if (d > N) return 0;
    return (d % MOD) * T(N / d) % MOD;
}

int main() {
    freopen("LANTERN.INP", "r", stdin);
    freopen("LANTERN.OUT", "w", stdout);
    cin >> N >> A >> B;
    ll L = A / gcdll(A, B) * B;            // A, B <= 1e9 nen BCNN <= 1e18, khong tran
    ll ans = (T(N) + S(A) + S(B) - S(L)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
