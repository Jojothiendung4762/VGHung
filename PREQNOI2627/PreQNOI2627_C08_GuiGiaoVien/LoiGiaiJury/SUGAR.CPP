// SUGAR - loi giai day du: dung nhieu bao 5 kg nhat co the; chi can lui toi da 2 bao 5 kg. O(1)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("SUGAR.INP", "r", stdin); freopen("SUGAR.OUT", "w", stdout);
    long long n; cin >> n;
    long long ans = -1;
    for (long long k = n / 5; k >= 0 && k >= n / 5 - 2; k--)
        if ((n - 5 * k) % 3 == 0) { ans = k + (n - 5 * k) / 3; break; }
    cout << ans << "\n";
}
