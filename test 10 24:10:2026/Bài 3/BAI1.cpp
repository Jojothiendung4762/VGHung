#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    int n;
    ll x;
    cin >> n;
    auto tronven = [] (const ll& a) {
        ll x = a;
        while (x > 0) {
            ll cuoi = x % 10;
            if (cuoi == 0 || a % cuoi != 0) {
                return false;
            }
            x /= 10;
        }
        return true;
    };
    vector<ll> kq;
    while (n--) {
        cin >> x;
        if (tronven(x)) kq.push_back(x);
    }
    cout << kq.size() << "\n";
    for (auto i : kq) {
        cout << i << " ";
    }
    fclose(stdin);
    fclose(stdout);
}