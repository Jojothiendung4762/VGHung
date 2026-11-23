#include <bits/stdc++>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("Sum.inp","r",stdin);
    freopen("Sum.out","w",stdout);
    ll l,r;
    cin >> l >> r;
    ll kq = 1;
    kq += (l + r) * ((r - l) + 1) / 2;
    if (l % 2 == 0 || l + 1 <= r) {
        kq += 2;
    }
    for (ll i = 3;i < l;i++) {
        ll a = l / i;
        if (l % i > 0) a++;
        if (a * i <= r) kq += i;
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}