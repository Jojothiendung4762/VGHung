#include <iostream>
using namespace std;
using str = string;
using ll = long long;

str congmot(str kq) {
    for (ll i = kq.size() - 1; i >= 0; i--) {
        if (kq[i] != '9') {
            kq[i]++;
            return kq;
        }
        kq[i] = '0';
    }
    return "1" + kq;
}

bool full9(str a) {
    for (auto i : a) {
        if (i != '9') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    str s;
    cin >> s;
    str ssongtrung = s;
    ll dai = s.size();
    if (full9(s)) {
        str kq;
        kq += '1';
        for (ll i = 1;i < dai;i++) {
            kq += '0';
        }
        kq += '1';
        cout << kq;
        return 0;
    }
    if (dai % 2 == 0) {
        str sotruoc;
        for (ll i = 0;i < dai / 2;i++) {
            sotruoc += s[i];
        }
        str sosau = sotruoc;
        reverse(sosau.begin(),sosau.end());
        for (ll i = dai / 2;i < dai;i++) {
            s[i] = sosau[i - dai / 2];        
        }
        while (s <= ssongtrung) {
            sotruoc = congmot(sotruoc);
            for (ll i = 0; i < dai / 2; i++) {
                s[i] = sotruoc[i];
            }
            sosau = sotruoc;
            reverse(sosau.begin(),sosau.end());
            for (ll i = dai / 2;i < dai;i++) {
                s[i] = sosau[i - dai / 2];        
            }
        }
    }
    else {
        str sotruoc;
        for (ll i = 0; i <= dai / 2; i++) {
            sotruoc += s[i];
        }
        str sosau;
        sosau = sotruoc;
        reverse(sosau.begin(),sosau.end());
        for (ll i = dai / 2 + 1; i < dai; i++) {
            s[i] = sosau[i - dai / 2];
        }
        while (s <= ssongtrung) {
            sotruoc = congmot(sotruoc);
            for (ll i = 0; i <= dai / 2; i++) {
                s[i] = sotruoc[i];
            }
            sosau = sotruoc;
            reverse(sosau.begin(),sosau.end());
            for (ll i = dai / 2 + 1; i < dai; i++) {
                s[i] = sosau[i - dai / 2];
            }
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
}