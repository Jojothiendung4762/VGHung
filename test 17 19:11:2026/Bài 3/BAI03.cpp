#include <iostream>
#include <string>
using namespace std;
using ll = long long;
using str = string;

str doixungtiep(str a) {
    int n = a.size();
    if (count(a.begin(),a.end(),'9') == n) {
        return "1" + str(n - 1,'0') + "1";
    }
    int mid = (n + 1) / 2;
    str l = a.substr(0,mid);
    str dao = l.substr(0,n / 2);
    reverse(dao.begin(),dao.end());
    str kq = l + dao;
    if (kq > a) return kq;
    int i = mid - 1;
    while (i >= 0 && l[i] == '9') {
        l[i--] = '0';
    }
    l[i]++;
    dao = l.substr(0,n / 2);
    reverse(dao.begin(),dao.end());
    return l + dao;
}

bool chiahetcho9(str& a) {
    int tong = 0;
    for (auto i : a) {
        tong += (i - '0');
    }
    return tong % 9 == 0;
}
int main() {
    freopen("BAI03.INP","r",stdin);
    freopen("BAI03.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str n;
    cin >> n;
    while (true) {
        n = doixungtiep(n);
        if (chiahetcho9(n)) {
            cout << n;
            break;
        }
    }
}