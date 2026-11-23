#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void file(string a) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((a + ".INP").c_str(), "r", stdin);
    freopen((a + ".OUT").c_str(), "w", stdout);
}

int main() {
    file("BAI1");
    ll n,k;
    cin >> n >> k;
    vector<ll> so(n + 1,true);
    so[0] = so[1] = false;
    for (ll i = 2;i * i <= n;i++) {
        if (so[i] == true) {
            for (ll j = i * i;j <= n;j += i) {
                so[j] = false;
            }
        }
    }
    for (ll i = 2;i <= n;i++) {
        if (i - k >= 2 && so[i] && so[i - k]) {
            cout << i - k << " " << i << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
}