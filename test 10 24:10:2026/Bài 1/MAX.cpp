#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MAX.INP","r",stdin);
    freopen("MAX.OUT","w",stdout);
    int n,m;
    cin >> n >> m;
    ll k = LLONG_MAX;
    for (int i = 2;i <= m;i++) {
        if (m % i == 0) {
            ll dem = 0;
            while (m % i == 0) {
                dem++;
                m /= i;
            }
            ll slxhtn = 0;
            ll a = n;
            while (a > 0) {
                a /= i;
                slxhtn += a;
            }
            k = min(k,slxhtn / dem);
        }
    }
    cout << k;
    fclose(stdin);
    fclose(stdout);
}