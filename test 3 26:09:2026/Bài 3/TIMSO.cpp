#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> sang(sqrt(2e9) + 1,true);
vector<ll> snt;

ll nghich_chuyen_thuat_thuc(ll a) {
    ll kq = 0;
    while (a > 0) {
        kq *= 10;
        kq += a % 10;
        a /= 10;
    }
    return kq;
}

bool checksnt(ll y) {
    if (y < 2) return false;
    for (ll i : snt) {
        if (i * i > y) break;
        if (y % i == 0) return false;
    }
    return true;
}

int main() {
    freopen("TIMSO.INP","r",stdin);
    freopen("TIMSO.OUT","w",stdout);
    ll p,q;
    cin >> p >> q;
    sang[0] = sang[1] = false;
    for (ll i = 2;i * i * i * i <= 2e9;i++) {
        if (sang[i] == true) {
            for (ll j = i * i;j * j <= 2e9;j += i) {
                sang[j] = false;
            }
        }
    }
    for (ll i = 2;i * i <= 2e9;i++) {
        if (sang[i]) snt.push_back(i);
    }
    for (ll x = p;x <= q;x++) {
        ll y = nghich_chuyen_thuat_thuc(x);
        if (checksnt(y)) cout << x << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}