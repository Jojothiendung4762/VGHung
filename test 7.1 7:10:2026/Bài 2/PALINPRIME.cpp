#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PALINPRIME.INP","r",stdin);
    freopen("PALINPRIME.OUT","w",stdout);
    int l,r;
    ll dem = 0;
    cin >> l >> r;
    vector<bool> lasnt(r + 1,true);
    lasnt[0] = lasnt[1] = false;
    for (ll i = 2;i * i <= r;i++) {
        if (lasnt[i] == true) {
            for (ll j = i * i;j <= r;j += i) {
                lasnt[j] = false;
            }
        }
    }
    for (ll i = l;i <= r;i++) {
        if (lasnt[i] == false) continue;
        str so = to_string(i);
        str sodao = so;
        reverse(sodao.begin(),sodao.end());
        if (sodao == so) dem++;
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}