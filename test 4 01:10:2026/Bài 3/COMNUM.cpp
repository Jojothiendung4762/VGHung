#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using str = string;

void file(string a) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((a + ".INP").c_str(), "r", stdin);
    freopen((a + ".OUT").c_str(), "w", stdout);
}

str nhan(str kq,ll a) {
    ll nho = 0;
    for (ll i = kq.size() - 1;i >= 0;i--) {
        ll so = (kq[i] - '0') * a + nho;
        kq[i] = so % 10 + '0';
        nho = so / 10;
    }
    if (nho > 0) {
        kq = to_string(nho) + kq;
    }
    return kq;
}
int main() {
    file("COMNUM");
    
    fclose(stdin);
    fclose(stdout);
}