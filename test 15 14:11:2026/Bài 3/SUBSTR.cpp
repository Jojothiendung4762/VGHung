#include <iostream>
#include <vector>
using namespace std;
using str = string;
using ll = long long;

int main() {
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    str s;
    cin >> k;
    cin >> s;
    int n = s.size();
    vector<int> dem(n + 1,0);
    dem[0] = 1;
    int ps = 0;
    ll kq = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '1') ps++;
        if (ps >= k) kq += dem[ps - k];
        dem[ps]++; 
    }
    cout << kq;
}