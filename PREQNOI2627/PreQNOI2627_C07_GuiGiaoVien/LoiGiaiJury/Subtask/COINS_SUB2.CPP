// COINS - Subtask 2 (loi giai day du): duyet so to 500 nghin; voi moi so to 500,
// so to 100 nghin hop le lap thanh mot doan lien tiep -> dem bang cong thuc. O(A)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("COINS.INP", "r", stdin); freopen("COINS.OUT", "w", stdout);
    long long A, B, C, X; cin >> A >> B >> C >> X;
    long long ans = 0;
    for (long long a = 0; a <= A && 500 * a <= X; a++) {
        long long r = (X - 500 * a) / 50;
        long long lo = (r - C <= 0) ? 0 : (r - C + 1) / 2, hi = min(B, r / 2);
        if (hi >= lo) ans += hi - lo + 1;
    }
    cout << ans << "\n";
}
