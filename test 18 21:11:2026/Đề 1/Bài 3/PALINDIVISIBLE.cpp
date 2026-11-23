#include <iostream>
#include <vector>
using namespace std;
using str = string;

int main() {
    freopen("PALINDIVISIBLE.INP","r",stdin);
    freopen("PALINDIVISIBLE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    str s;
    cin >> n >> k >> s;
    vector<int> ps(n + 1);
    ps[0] = 0;
    for (int i = 0;i < n;i++) {
        ps[i + 1] = ps[i] + (int)s[i];
    }
    int kq = 0;
    for (int i = 0;i < n;i++) {
        int l = i,r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if ((ps[r + 1] - ps[l]) % k == 0) {
                kq = max(kq,r - l + 1);
            }
            l--;
            r++;
        }
        l = i,r = i + 1;
         while (l >= 0 && r < n && s[l] == s[r]) {
            if ((ps[r + 1] - ps[l]) % k == 0) {
                kq = max(kq,r - l + 1);
            }
            l--;
            r++;
        }
    }
    cout << kq;
}