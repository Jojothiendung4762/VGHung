#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("DIVISIBLEODDLEN.INP","r",stdin);
    freopen("DIVISIBLEODDLEN.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<ll> chan(k,0),le(k,0);
    chan[0]++;
    ll x,tong = 0,kq = 0;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        tong = (tong + x) % k;
        if (i % 2 == 0) {
            kq += le[tong];
            chan[tong]++;
        }
        else {
            kq += chan[tong];
            le[tong]++;
        }
    }
    cout << kq;
}