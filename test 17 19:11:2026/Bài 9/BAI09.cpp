#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI09.INP","r",stdin);
    freopen("BAI09.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b;
    cin >> a >> b;
    ll d = gcd(a,b);
    cout << a / d << " " << b / d;
}