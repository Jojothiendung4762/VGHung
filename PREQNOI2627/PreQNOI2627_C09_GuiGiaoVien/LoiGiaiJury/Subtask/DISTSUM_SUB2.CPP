/*
 * Bai 4 - DISTSUM, Subtask 2 (cay la duong thang 1 - 2 - ... - N)
 * Y tuong: dist(i, j) = |i - j|. Tong khoang cach tu i:
 *          (1 + 2 + ... + (i-1)) + (1 + 2 + ... + (N-i))
 *          = (i-1)i/2 + (N-i)(N-i+1)/2.
 * Do phuc tap: O(N).
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("DISTSUM.INP", "r", stdin);
    freopen("DISTSUM.OUT", "w", stdout);

    ll n;
    scanf("%lld", &n);                  // khong can doc cac canh
    for (ll i = 1; i <= n; i++) {
        ll left = (i - 1) * i / 2;
        ll right = (n - i) * (n - i + 1) / 2;
        printf("%lld%c", left + right, i == n ? '\n' : ' ');
    }
    return 0;
}
