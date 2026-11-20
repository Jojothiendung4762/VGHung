#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI06.INP","r",stdin);
    freopen("BAI06.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int p;
    cin >> n >> p;
    ll kq = 0;
    while (n > 0) {
        kq += n % p;
        n /= p;
    }
    cout << kq;
}