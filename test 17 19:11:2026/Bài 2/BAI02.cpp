#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("BAI02.INP","r",stdin);
    freopen("BAI02.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r,k;
    cin >> l >> r >> k;
    vector<int> souoc(r + 1,1);
    for (int i = 1;i <= r / 2;i++) {
        for (int j = i * 2;j <= r;j += i) {
            souoc[j]++;
        }
    }
    ll kq = 0;
    for (int i = l;i <= r;i++) {
        if (souoc[i] == k) kq += i;
    }
    cout << kq;
}