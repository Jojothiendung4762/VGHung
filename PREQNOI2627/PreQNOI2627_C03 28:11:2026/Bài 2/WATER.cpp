#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("WATER.INP","r",stdin);
    freopen("WATER.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,q;
    cin >> n >> m >> q;
    vector<ll> cay(n + 2,0);
    int l,r,x;
    for (int i = 1;i <= m;i++) {
        cin >> l >> r >> x;
        cay[l] += x;
        cay[r + 1] -= x;
    }
    for (int i = 2;i <= n;i++) {
        cay[i] += cay[i - 1];
    }
    ll t;
    while (q--) {
        cin >> t;
        ll p = lower_bound(cay.begin() + 1,cay.begin() + n + 1,t) - cay.begin();
        cout << n - p + 1 << "\n";
    }
}