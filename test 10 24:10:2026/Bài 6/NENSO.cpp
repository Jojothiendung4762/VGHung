#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NENSO.INP","r",stdin);
    freopen("NENSO.OUT","w",stdout);
    ll n,x;
    cin >> n;
    while (n--) {
        cin >> x;
        while (x >= 10) {
            ll tong = 0;
            while (x > 0) {
                tong += x % 10;
                x /= 10;
            }
            x = tong;
        }
        cout << x << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}