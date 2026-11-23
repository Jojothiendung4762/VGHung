#include <iostream>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("STRPALINCNT.INP","r",stdin);
    freopen("STRPALINCNT.OUT","w",stdout);
    string s;
    cin >> s;
    int dai = s.size(),dem = 0;
    for (int i = 1;i < dai;i++) {
        int l = i - 1;
        int r = i + i;
        while (l >= 0 && r < dai && s[l] == s[r]) {
            dem++;
            l--;
            r++;
        }
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}