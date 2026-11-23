#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUMPRIME.INP","r",stdin);
    freopen("NUMPRIME.OUT","w",stdout);
    int n,dem = 0;
    cin >> n;
    vector<bool> snt(n + 1,true);
    snt[0] = snt[1] = false;
    for (int i = 2;i * i <= n;i++) {
        if (snt[i]) {
            for (int j = i * i;j <= n;j += i) {
                snt[j] = false;
            }
        }
    }
    auto tongchuso = [] (int a) {
        ll tong = 0;
        ll x = a;
        while (x > 0) {
            tong += x % 10;
            x /= 10;
        }
        return tong;
    };
    for (int i = 1;i <= n;i++) {
        if (snt[i] && snt[tongchuso(i)]) dem++;
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}