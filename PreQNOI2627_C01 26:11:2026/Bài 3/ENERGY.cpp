#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("ENERGY.INP","r",stdin);
    freopen("ENERGY.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,r;
    cin >> n >> l >> r;
    vector<ll> s(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    vector<ll> dp(n + 1,0);
    for (int i = 1;i <= n;i++) {
        dp[i] = dp[i - 1];
        for (int j = max(1,i - r + 1);j <= i - l + 1;j++) {
            dp[i] = max(dp[i],dp[j - 1] + (s[i] - s[j - 1]));
        }
    }
    cout << dp[n];
}