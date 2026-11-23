#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("EVENPRIME.INP","r",stdin);
    freopen("EVENPRIME.OUT","w",stdout);
    int l,r;
    ll dem = 0;
    cin >> l >> r;
    static vector<int> untnn(r + 1,0);
    for (int i = 2;i <= r;i++) {
        if (untnn[i] == 0) {
            for (int j = i;j <= r;j += i) {
                if (untnn[j] == 0) {
                    untnn[j] = i;
                }
            }
        }
    }
    for (int i = l;i <= r;i++) {
        int x = i;
        ll tongchan = 0;
        ll tongle = 0;
        while (x > 1) {
            int p = untnn[x];
            if (p % 2 == 0) {
                tongchan += p;
            }
            else {
                tongle += p;
            }
            x /= p;
        }
        if (tongchan == tongle) dem++;
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}