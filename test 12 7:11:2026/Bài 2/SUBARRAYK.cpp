#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SUBARRAYK.INP","r",stdin);
    freopen("SUBARRAYK.OUT","w",stdout);
    int n;ll k;
    cin >> n >> k;
    vector<ll> so(n);
    for (auto &i : so) {
        cin >> i;
    }
    int l = 0,r = 0;
    ll tong = 0;
    ll kq = LLONG_MAX;
    while (r < n) {
        tong += so[r];
        while (tong >= k) {
            kq = min(kq,(ll)r - l + 1);
            tong -= so[l];
            l++;
        }
        r++;
    }
    if (kq == LLONG_MAX) cout << -1;
    else cout << kq;
    fclose(stdin);
    fclose(stdout);
}