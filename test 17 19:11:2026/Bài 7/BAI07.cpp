#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("BAI07.INP","r",stdin);
    freopen("BAI07.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2;
        return 0;
    }
    int m = (n - 1) / 2;
    vector<int> snt(m + 1,true);
    snt[0] = false;
    for (int i = 3;i * i <= n;i += 2) {
        if (snt[i / 2]) {
            for (int j = i * i / 2;j <= m;j += i) {
                snt[j] = false;
            }
        }
    }
    for (int i = m;i >= 1;i--) {
        if(snt[i]) {
            cout << i * 2 + 1;
            return 0; 
        }
    }
}