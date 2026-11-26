// SUGAR - Subtask 1: N <= 5000 -> thu moi so bao 5 kg. O(N)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("SUGAR.INP", "r", stdin); freopen("SUGAR.OUT", "w", stdout);
    int n; cin >> n;
    int ans = -1;
    for (int k = 0; 5 * k <= n; k++)
        if ((n - 5 * k) % 3 == 0) {
            int c = k + (n - 5 * k) / 3;
            if (ans == -1 || c < ans) ans = c;
        }
    cout << ans << "\n";
}
