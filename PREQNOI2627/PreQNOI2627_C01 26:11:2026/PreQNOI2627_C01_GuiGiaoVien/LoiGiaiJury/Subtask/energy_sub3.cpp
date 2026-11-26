#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

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
    vector<long long> F(n + 1, -INF);

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];

        if (i >= L) {
            long long new_segment = dp[i - L] + (S[i] - S[i - L]);
            long long extend_segment = F[i - 1] + A[i];
            F[i] = max(new_segment, extend_segment);
            dp[i] = max(dp[i], F[i]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}