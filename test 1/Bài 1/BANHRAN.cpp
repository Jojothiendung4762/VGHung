#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll scp(ll a) {
    ll b = sqrt(a);
    return b * b == a;
}
int main() {
    freopen("BANHRAN.INP","r",stdin);
    freopen("BANHRAN.OUT","w",stdout);
    int n;
    ll a;
    ll dem = 0,toida = 0,x;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a;
        if (scp(a) == true) {
            dem++;
            toida = max(toida,a);
        }
    }
    cout << dem << endl;
    if (dem == 0) {
        cout << -1;
    }
    else {
        cout << toida;
    }
    fclose(stdin);
    fclose(stdout);
}