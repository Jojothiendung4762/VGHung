#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
vector<bool> sang(sqrt(2e9) + 1,true);
vector<ll> snt;
bool checksnt(ll y) {
    if (y < 2) return false;
    if (y == 2) return true;
    if (y % 2 == 0) return false;
    for (ll i : snt) {
        if (i * i > y) break;
        if (y % i == 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DAYNGTO.IN","r",stdin);
    freopen("DAYNGTO.OUT","w",stdout);
    int n;
    cin >> n;
    sang[0] = sang[1] = false;
    for (int i = 2;i * i * i * i <= 2e9;i++) {
        if (sang[i]) {
            for (int j = i * i;j * j <= 2e9;j += i) {
                sang[j] = false;
            }
        }
    } 
    for (int i = 2;i * i <= 2e9;i++) {
        if (sang[i]) snt.push_back(i);
    }
    ll x,toida = LLONG_MIN,dem = 0,chiso;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        if (checksnt(x)) {
            dem++;
            if (toida < x) {
                toida = x;
                chiso = i;
            }
        }
    }
    if (dem == 0) {
        cout << "khong co";
        return 0;
    }
    cout << dem << " " << toida << " " << chiso;
    fclose(stdin);
    fclose(stdout);
}