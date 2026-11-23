#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI05.INP","r",stdin);
    freopen("BAI05.OUT","w",stdout);
    int n;
    ll a;
    cin >> n;
    vector<bool> snt(1e6 + 1,true);
    snt[0] = snt[1] = false;
    for (int i = 2;i * i <= 1e6;i++) {
        if (snt[i]) {
            for (int j = i * i;j <= 1e6;j += i) {
                snt[j] = false;
            }
        }
    }
    auto dung = [&snt] (const ll& a) {
        ll can = sqrtl(a);
        return can * can == a && snt[can];
    };
    while (n--) {
        cin >> a;
        if (dung(a)) {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}