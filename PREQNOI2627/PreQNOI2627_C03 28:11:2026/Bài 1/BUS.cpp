#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    freopen("BUS.INP","r",stdin);
    freopen("BUS.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,l,r;
    cin >> a >> b >> l >> r;
    ll bcnn = a / gcd(a,b) * b;
    cout << (r / bcnn) - ((l - 1) / bcnn) << "\n" << ((r / a) - ((l - 1) / a)) + ((r / b) - ((l - 1) / b)) - ((r / bcnn) - ((l - 1) / bcnn));
}