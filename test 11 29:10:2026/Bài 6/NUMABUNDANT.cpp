#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NUMABUNDANT.INP","r",stdin);
    freopen("NUMABUNDANT.OUT","w",stdout);
    int l,r;
    cin >> l >> r;
    vector<ll> sum_uoc_real(r + 1,0);
    for (ll i = 1;i <= r / 2;i++) {
        for (ll j = i * 2;j <= r;j += i) {
            sum_uoc_real[j] += i;
        }
    }
    int dem = 0,toida = 0;
    for (int i = l;i <= r;i++) {
        if (sum_uoc_real[i] > i) {
            dem++;
            toida = max(toida,i);
        }
    }
    cout << dem << "\n" << toida;
    fclose(stdin);
    fclose(stdout);
}