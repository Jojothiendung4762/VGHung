#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("BAI04.INP","r",stdin);
    freopen("BAI04.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r,k;
    cin >> l >> r >> k;
    vector<int> snt(r + 1,true);
    snt[0] = snt[1] = false;
    for (int i = 2;i * i <= r;i++) {
        if (snt[i]) {
            for (int j = i * i;j <= r;j += i) {
                snt[j] = false;
            }
        }
    }
    int dem = 0;
    for (int i = l;i + k <= r;i++) {
        if (snt[i] && snt[i + k]) dem++;
    }
    cout << dem;
}