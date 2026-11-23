#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DIGITSUMK.INP","r",stdin);
    freopen("DIGITSUMK.OUT","w",stdout);            
    vector<int> snt{0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,73,79,83,
                    89,97};
    int l,r,k,dem = 0;
    cin >> l >> r >> k;
    k = snt[k];
    for (int i = l;i <= r;i++) {
        ll tong = 0;
        ll x = i;
        while (x > 0) {
            tong += x % 10;
            x /= 10;
        }
        if (tong == k) {
            ++dem;
        }
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}