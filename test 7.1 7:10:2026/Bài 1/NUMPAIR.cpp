#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUMPAIR.INP","r",stdin);
    freopen("NUMPAIR.OUT","w",stdout);
    int r,k = 0;
    cin >> r;
    vector<ll> tonguoc(r + 1,1);
    vector<pair<ll,ll>> kq;
    tonguoc[1] = 0;
    for (ll i = 2;i <= r / 2;i++) {
        for (ll j = i * 2;j <= r;j += i) {
            tonguoc[j] += i; 
        }
    }
    for (int i = 1;i <= r;i++) {
        ll j = tonguoc[i];
        if (j <= r && i < j && tonguoc[j] == i) {
            k++;
            kq.push_back({i,j});
        }
    }
    cout << k << "\n";
    for (auto i : kq) {
        cout << i.first << " " << i.second << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}