#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("GRIDDP.INP","r",stdin);
    freopen("GRIDDP.OUT","w",stdout);
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matran(m + 1,vector<int>(n + 1));
    vector<vector<ll>> dp(m + 1,vector<ll>(n + 1));
    for (int hang = 1;hang <= m;hang++) {
        for (int cot = 1;cot <= n;cot++) {
            cin >> matran[hang][cot];
        }
    }
    dp[1][1] = matran[1][1];
    for (int hang = 2;hang <= m;hang++) {
        dp[hang][1] = dp[hang - 1][1] + matran[hang][1]; 
    }
    for (int cot = 2;cot <= n;cot++) {
        dp[1][cot] = dp[1][cot - 1] + matran[1][cot];
    }
    for (int hang = 2;hang <= m;hang++) {
        for (int cot = 2;cot <= n;cot++) {
            dp[hang][cot] = max(dp[hang - 1][cot],dp[hang][cot - 1]) + matran[hang][cot];
        }
    }
    cout << dp[m][n];
    fclose(stdin);
    fclose(stdout);
}