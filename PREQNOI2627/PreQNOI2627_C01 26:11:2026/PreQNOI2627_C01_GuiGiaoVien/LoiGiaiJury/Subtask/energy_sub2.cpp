#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("energy.inp", "r", stdin);
    freopen("energy.out", "w", stdout);

    int n, L, R;
    cin >> n >> L >> R;

    vector<long long> A(n + 1);
    vector<long long> S(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= i; ++j) {
            int len = i - j + 1;
            if (len >= L && len <= R) {
                dp[i] = max(dp[i], dp[j - 1] + S[i] - S[j - 1]);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}