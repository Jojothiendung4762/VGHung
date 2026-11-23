#include <bits/stdc++.h>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("STRTRANS.INP","r",stdin);
    freopen("STRTRANS.OUT","w",stdout);
    int n,k,khac = 0;
    str s;
    cin >> n >> k >> s;
    map<char,int> dem;
    int l = 0,kq = 0;
    for (int r = 0;r < n;r++) {
        dem[s[r]]++;
        while (dem[s[r]] > k) {
            dem[s[l]]--;
            l++;
        }
        kq = max(kq,r - l + 1);
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}