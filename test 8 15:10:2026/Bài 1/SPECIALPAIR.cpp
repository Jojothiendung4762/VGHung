#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SPECIALPAIR.INP","r",stdin);
    freopen("SPECIALPAIR.OUT","w",stdout);
    int n,d,m,dem = 0;
    cin >> n >> d >> m;
    for (int i = 1;i <= n / d;i++) {
        for (int j = i + 1;j <= n / d;j++) {
            if (gcd(i,j) == 1 && i * j <= m / d) {
                dem++;
            }
        }
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}