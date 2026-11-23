#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("PAIRXORSUM.INP","r",stdin);
    freopen("PAIRXORSUM.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> so(n);
    for (auto &i : so) {
        cin >> i;
    }
    sort(so.begin(),so.end());
    ll xormax = -1;
    int l = 0,r = n - 1;
    while (l < r) {
        ll tong = so[l] + so[r];
        if (tong == k) {
            xormax = max(xormax,so[l] ^ so[r]);
            l++;
            r--;
        }
        else if (tong > k) {
            r--;
        }
        else l++;
    }
    cout << xormax;    
}