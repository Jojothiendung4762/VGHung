#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("UOCSO.INP","r",stdin);
    freopen("UOCSO.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll kq = 1;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        bool snt = true;
        for (int j = 2;j * j <= i;j++) {
            if (i % j == 0) {
                snt = false;
                break;
            }
        }
        
        if (snt) {
            int mu = 0,x = n;
            while (x) {
                x /= i;
                mu += x;
            }
            kq *= (mu + 1);
        }
    }
    cout << kq;
}