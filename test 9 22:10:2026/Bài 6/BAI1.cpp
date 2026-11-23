#include <iostream>
using namespace std;
using ll = long long;

ll tongdoan(ll a,ll& b) {
    return (a + b) * (b - a + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ll l,r;
    cin >> l >> r;
    ll t = l,p = r - 1,kq = l,nhonhat = LLONG_MAX;
    while (t <= p) {
        ll m = (t + p) / 2;
        ll tongtruoc = tongdoan(l,m);
        ll tongsau = tongdoan(m + 1,r);
        ll lech = abs(tongtruoc - tongsau);
        if (lech < nhonhat) {
            nhonhat = lech;
            kq = m;
        }
        if (tongtruoc < tongsau) {
            t = m + 1;
        }
        else {
            p = m - 1;
        }
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}