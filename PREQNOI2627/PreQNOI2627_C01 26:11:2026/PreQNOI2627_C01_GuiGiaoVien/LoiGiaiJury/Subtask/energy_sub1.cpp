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
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= i; ++j) {
            int len = i - j + 1;
            if (len >= L && len <= R) {
                long long sum_seg = 0;
                for (int k = j; k <= i; ++k) {
                    sum_seg += A[k];
                }
                dp[i] = max(dp[i], dp[j - 1] + sum_seg);
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}