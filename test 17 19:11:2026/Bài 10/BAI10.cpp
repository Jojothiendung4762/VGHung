#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI10.INP","r",stdin);
    freopen("BAI10.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l,r,a,b;
    cin >> l >> r >> a >> b;
    cout << (r / a - (l - 1) / a) + (r / b - (l - 1) / b) - (r / lcm(a,b) - (l - 1) / lcm(a,b));
}