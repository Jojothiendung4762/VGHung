#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

ll d = 1000000000 + 7;
ll tong(ll a) {
    ll b = a + 1;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    return (a % d) * (b % d) % d;
}

int main() {
    freopen("LANTERN.INP","r",stdin);
    freopen("LANTERN.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,a,b;
    cin >> n >> a >> b;
    ll bcnn = a / gcd(a,b) * b;
    ll sa = a % d * tong(n / a) % d;
    ll sb = b % d * tong(n / b) % d;
    ll sl = bcnn % d * tong(n / bcnn) % d;
    cout << ((tong(n) + sa + sb - sl + d) % d);
}