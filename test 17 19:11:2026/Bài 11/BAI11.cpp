#include <iostream>
using namespace std;
using str = string;

int main() {
    freopen("BAI11.INP","r",stdin);
    freopen("BAI11.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str s,kq;
    cin >> s;
    int dai = s.size();
    int dem = 1;
    for (int i = 1;i < dai;i++) {
        if (s[i] == s[i - 1]) dem++;
        else {
            kq += to_string(dem);
            kq += s[i - 1];
            dem = 1;
        }
    }
    kq += to_string(dem);
    kq += s[dai - 1];
    cout << kq;
}