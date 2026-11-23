#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PRIMEFACT.INP","r",stdin);
    freopen("PRIMEFACT.OUT","w",stdout);
    int l,r,k,m,dem = 0;
    cin >> l >> r >> k >> m;
    vector<int> sount(r + 1,0);
    vector<ll> tongunt(r + 1,0);
    for (int i = 2;i <= r;i++) {
        if (sount[i] == 0) {
            for (int j = i;j <= r;j += i) {
                sount[j]++;
                tongunt[j] += i;
            }
        }
    } 
    for (int i = l;i <= r;i++) {
        if (sount[i] == k && tongunt[i] % m == 0) {
            dem++;
        }
    }
    cout << dem;
    fclose(stdin);
    fclose(stdout);
}