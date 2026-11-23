#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("KDISTINCTPRIME.INP","r",stdin);
    freopen("KDISTINCTPRIME.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r,k;
    cin >> l >> r >> k;
    vector<int> sotsnt(r + 1,0);
    for (int i = 2;i<= r;i++) {
        if (sotsnt[i] == 0) {
            for (int j = i;j <= r;j += i) {
                sotsnt[j]++;
            }
        }
    }
    int dem = 0;
    for (int i = l;i <= r;i++) {
        if (sotsnt[i] == k) dem++;
    }
    cout << dem;
}