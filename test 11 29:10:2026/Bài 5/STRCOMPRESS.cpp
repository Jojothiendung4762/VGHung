#include <iostream>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("STRCOMPRESS.INP","r",stdin);
    freopen("STRCOMPRESS.OUT","w",stdout);
    str s,kq;
    cin >> s;
    int dai = s.size();
    int dem = 1;
    for (int i = 1;i < dai;i++) {
        if (s[i] == s[i - 1]) dem++;
        else {
            kq += s[i - 1];
            kq += to_string(dem);
            dem = 1;
        }
    }
    kq += s[dai - 1];
    kq += to_string(dem);
    cout << kq << "\n" << (int)s.size() - (int)kq.size();
    fclose(stdin);
    fclose(stdout);
}