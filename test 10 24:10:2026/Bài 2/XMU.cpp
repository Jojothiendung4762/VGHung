#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("XMU.INP","r",stdin);
    freopen("XMU.OUT","w",stdout);
    int k,x,n;
    cin >> k;
    while (k--) {
        cin >> x >> n;
        ll y = x;
        for (int i = 2;i <= n;i++) {
            y *= x;
            y = y % 100;
        }
        cout << y << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}