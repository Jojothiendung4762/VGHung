#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("MEMO.INP","r",stdin);
    freopen("MEMO.OUT","w",stdout);
    ll n,t,m,tong = 0;
    cin >> n >> t >> m;
    vector<ll> so(n);
    for (auto &i : so) {
        cin >> i;
    }
    for (auto i : so) {
        tong += i;
    }
    ll kq = m / n * tong;
    ll conlai = m % n;
    t = t - 1;
    if (conlai > 0) {
        for (ll i = t;conlai--;i++) {
           if (t == n) {
            t = 0;
           } 
           kq += so[t];
           t++;
        }
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}