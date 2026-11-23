#include <iostream>
#include <map>
using namespace std;
using ll = long long;
using str = string;

int main() {
    freopen("MATMA.INP","r",stdin);
    freopen("MATMA.OUT","w",stdout);
    str s;
    ll toida = 0,kq = -1;
    cin >> s;
    map<int,int> dem;
    for (auto i : s) {
        if ('0' <= i && i <= '9') {
            dem[i - '0']++;
        }
    }
    for (auto i : dem) {
        if (i.second >= toida) {
            kq = i.first;
            toida = i.second;
        }
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}