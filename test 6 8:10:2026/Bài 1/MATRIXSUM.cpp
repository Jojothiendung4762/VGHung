#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MATRIXSUM.INP", "r", stdin);
    freopen("MATRIXSUM.OUT", "w", stdout);
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matran(m + 1,vector<int>(n + 1));
    for (int hang = 1;hang <= m;hang++) {
        for (int cot = 1;cot <= n;cot++) {
            cin >> matran[hang][cot];
        }
    }
    ll tongkq = LLONG_MIN;
    for (int hangdau = 1;hangdau <= m;hangdau++) {
        vector<ll> hangmoi(n + 1,0);
        for (int hangcuoi = hangdau;hangcuoi <= m;hangcuoi++) {
            for (int i = 1;i <= n;i++) {
                hangmoi[i] += matran[hangcuoi][i];
            }
            ll tong = 0,toida = LLONG_MIN;
            for (int i = 1;i <= n;i++) {
                tong = max(hangmoi[i],hangmoi[i] + tong);
                toida = max(toida,tong);
            }
            tongkq = max(tongkq,toida);
        }
    }
    cout << tongkq;
    fclose(stdin);
    fclose(stdout);
}