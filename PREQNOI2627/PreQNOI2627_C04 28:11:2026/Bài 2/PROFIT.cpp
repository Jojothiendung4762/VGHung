#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
    freopen("PROFIT.INP","r",stdin);
    freopen("PROFIT.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    map<ll,ll> dem;
    dem[0] = 1;
    ll pre = 0,kq = 0,x;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        pre += x;
        kq += dem[pre - k];
        dem[pre]++;
    }
    cout << kq;
}