/*
 * Bai 1 - DIGITS: Viet so (PreQNOI 2026-2027, Contest 10)
 * Nguon : Baekjoon Online Judge 1748 "Viet noi cac so 1" (Han Quoc).
 *
 * Y tuong (dem theo nhom so co cung so chu so):
 *   Cac so co d chu so nam trong doan [p, 10p - 1] voi p = 10^(d-1).
 *   Trong doan [1, N], nhom d co (min(N, 10p - 1) - p + 1) so, moi so d chu so.
 *   Cong lai qua cac nhom d = 1, 2, ... cho den khi p > N.
 *
 * Do phuc tap: O(so chu so cua N). Dap an toi khoang 1,6 * 10^18 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);

    // 1. Doc du lieu
    ll n;
    cin >> n;

    // 2. Cong so chu so cua tung nhom
    ll answer = 0;
    ll p = 1;                            // so nho nhat co d chu so
    int d = 1;
    while (p <= n) {
        ll last = min(n, p * 10 - 1);    // so lon nhat co d chu so va khong vuot N
        answer += (last - p + 1) * d;
        p *= 10;
        d++;
    }

    // 3. Ghi ket qua
    cout << answer << "\n";
    return 0;
}
