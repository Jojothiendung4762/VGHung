#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int n, K;
vector<long long> C;
vector<vector<int>> adj;
vector<int> sz;
vector<vector<array<long long, 2>>> dp;

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u].assign(2, {-INF, -INF});
    dp[u][0][0] = 0;
    dp[u][1][1] = C[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        int new_sz = sz[u] + sz[v];
        vector<array<long long, 2>> next_dp(new_sz + 1, {-INF, -INF});
        for (int j = 0; j <= sz[u]; ++j) {
            for (int t = 0; t <= sz[v]; ++t) {
                if (dp[u][j][0] != -INF) {
                    long long best_v = max(dp[v][t][0], dp[v][t][1]);
                    if (best_v != -INF) {
                        next_dp[j + t][0] = max(next_dp[j + t][0], dp[u][j][0] + best_v);
                    }
                }
                if (dp[u][j][1] != -INF && dp[v][t][0] != -INF) {
                    next_dp[j + t][1] = max(next_dp[j + t][1], dp[u][j][1] + dp[v][t][0]);
                }
            }
        }

        sz[u] = new_sz;
        dp[u] = move(next_dp);
        dp[v].clear();
        dp[v].shrink_to_fit();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("OUTPOST.INP", "r", stdin);
    freopen("OUTPOST.OUT", "w", stdout);

    cin >> n >> K;

    C.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
    }

    adj.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sz.resize(n + 1, 0);
    dp.resize(n + 1);
    dfs(1, 0);
    long long ans = max(dp[1][K][0], dp[1][K][1]);
    cout << ans << "\n";

    return 0;
}