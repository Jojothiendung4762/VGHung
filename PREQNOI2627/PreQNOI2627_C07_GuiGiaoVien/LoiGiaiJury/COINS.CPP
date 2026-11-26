// COINS - loi giai day du: duyet so to 500, dem so to 100 bang cong thuc. O(A)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("COINS.INP", "r", stdin); freopen("COINS.OUT", "w", stdout);
    long long A, B, C, X; cin >> A >> B >> C >> X;
    long long ans = 0;
    for (long long a = 0; a <= A && 500 * a <= X; a++) {
        long long r = (X - 500 * a) / 50;          // can 100*b + 50*c = 50*r  <=>  2b + c = r
        long long lo = (r - C <= 0) ? 0 : (r - C + 1) / 2;   // c = r - 2b <= C
        long long hi = min(B, r / 2);                         // c = r - 2b >= 0
        if (hi >= lo) ans += hi - lo + 1;
    }
    cout << ans << "\n";
}
