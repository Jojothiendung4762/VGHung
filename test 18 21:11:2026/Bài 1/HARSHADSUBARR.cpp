#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("HARSHADSUBARR.INP","r",stdin);
    freopen("HARSHADSUBARR.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> tong(1e6 + 1);
    tong[0] = 0;
    for (int i = 1;i <= 1e6;i++) {
        tong[i] = tong[i / 10] + i % 10;
    }
    int n;
    cin >> n;
    ll x;
    int mottrieu = 1000000;
    int hientai = 0,toida = 0;
    for (int i = 0;i < n;i++) {
        cin >> x;
        int s = tong[x % mottrieu] + tong[(x / mottrieu) % mottrieu] + tong[(x / mottrieu) / mottrieu];
        if (x % s == 0) {
            hientai++;
            if (hientai > toida) toida = hientai;
        }
        else {
            hientai = 0; 
        }
    } 
    cout << toida;   
}