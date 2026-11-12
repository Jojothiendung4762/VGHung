#include <iostream>
#include <map>
#include <string>
using namespace std;
using str = string;

int main() {
    freopen("Bai1.INP","r",stdin);
    freopen("Bai1.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    str s,kq;
    map<char,int> dem;
    cin >> n >> k >> s;
    kq = s.substr(0,k);
    int toida = 0;
    for (auto i : kq) {
        if (dem[i] == 0) toida++;
        dem[i]++;
    }
    dem.clear();
    int l = 0,khac = 0;
    for (int r = 0;r < n;r++) {
        if (dem[s[r]] == 0) khac++;
        dem[s[r]]++;
        if (r - l + 1 < k) continue;
        if (r - l + 1 == k) {
            if (khac > toida) {
                toida = khac;
                kq = s.substr(l,k);
            }
        }
        if (r - l + 1 > k) {
            dem[s[l]]--;
            if (dem[s[l]] == 0) khac--;
            l++;
        }
    }
    cout << toida << " " << kq;
}