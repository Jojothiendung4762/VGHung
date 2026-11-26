// KBASE - Subtask 1: N <= 6, K <= 10 -> sinh moi so co N chu so trong he co so K va kiem tra.
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("KBASE.INP", "r", stdin); freopen("KBASE.OUT", "w", stdout);
    int n, k; cin >> n >> k;
    long long lo = 1; for (int i = 1; i < n; i++) lo *= k;   // K^(N-1)
    long long hi = lo * k, cnt = 0;                          // cac so trong [K^(N-1), K^N)
    for (long long v = lo; v < hi; v++) {
        long long x = v; bool prevZero = false, ok = true;
        while (x > 0) {
            bool z = (x % k == 0);
            if (z && prevZero) { ok = false; break; }
            prevZero = z; x /= k;
        }
        if (ok) cnt++;
    }
    cout << cnt % 1000000007LL << "\n";
}
