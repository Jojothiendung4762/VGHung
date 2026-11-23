#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CHIAQUA.INP","r",stdin);
    freopen("CHIAQUA.OUT","w",stdout);
    int x,y;
    cin >> x >> y;
    int ucln = gcd(x,y);
    ll kq = 1;
    for (int i = 2;i * i <= ucln;i++) {
        int dem = 0;
        while (ucln % i == 0) {
            dem++;
            ucln /= i;
        }
        kq *= (dem + 1);
    }
    if (ucln > 1) {
        kq *= 2;
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}