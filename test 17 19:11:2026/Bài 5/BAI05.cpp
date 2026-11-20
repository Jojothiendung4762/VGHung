#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI05.INP","r",stdin);
    freopen("BAI05.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,c,d;
    int n,x;
    cin >> a >> b >> c >> d >> n;
    ll tong = 0;
    for (int i = 0;i < n;i++) {
        cin >> x;
        if (x <= 50) tong += (x * a);
        else if (x > 50 && x <= 100) tong += (50 * a + (x - 50) * b);
        else if (x > 100 && x <=200) tong += (50 * a + 50 * b + (x - 100) * c);
        else tong += (50 * (a + b + 2 * c) + (x - 200) * d);
    }
    cout << tong;
}