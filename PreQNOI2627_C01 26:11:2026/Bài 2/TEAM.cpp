#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    ll kq = 0;
    unordered_map<ll,ll> dem;
    for (int i = 0;i < n;i++) {
        ll x = a[i] - b[i];
        kq += dem[-x];
        dem[x]++;
    }
    cout << kq;
}