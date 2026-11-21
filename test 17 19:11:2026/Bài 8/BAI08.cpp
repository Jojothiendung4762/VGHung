#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI08.INP","r",stdin);
    freopen("BAI08.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll dem = 0;
    for (ll i = 1;i <= n;i *= 2) {
        for (ll j = i;j <= n;j *= 3) {
            for (ll k = j;k <= n;k *= 5) {
                dem++;
                if (k > n /5) break;
            }
            if (j > n / 3) break;
        }
        if (i > n / 2) break;
    }
    cout << dem;
}