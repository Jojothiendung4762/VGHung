#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("BOTTLE.INP","r",stdin);
    freopen("BOTTLE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    ll toida = (n -1) / (k - 1);
    cout << n + toida << "\n" << n - toida * (k - 1);
}