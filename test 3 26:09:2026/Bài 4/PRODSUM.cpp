#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void file(string a) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((a + ".INP").c_str(), "r", stdin);
    freopen((a + ".OUT").c_str(), "w", stdout);
}

int main() {
    file("PRODSUM");
    ll n,tong = 0,g = 0;
    cin >> n;
    vector<ll> so(n + 1);
    for (ll i = 1;i <= n;i++) {
        cin >> so[i];
        tong += so[i];
        g += i * so[i];
    }
    ll kq = g,tongtruoc = 0;
    for (ll i = 1;i <= n;i++) {
        ll tongsau = tong - tongtruoc - so[i];
        ll thaydoikhidoilendau = tongtruoc - (i - 1) * so[i];
        ll thaydoikhidoivecuoi = (n - i) * so[i] - tongsau;
        kq = max({kq,g + thaydoikhidoilendau,g + thaydoikhidoivecuoi});
        tongtruoc += so[i];
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}