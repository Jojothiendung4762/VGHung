#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("FUND.INP","r",stdin);
    freopen("FUND.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int x,y;
    cin >> n >> x >> y;
    cout << n * x + (ll)(n / 3) * y;
}