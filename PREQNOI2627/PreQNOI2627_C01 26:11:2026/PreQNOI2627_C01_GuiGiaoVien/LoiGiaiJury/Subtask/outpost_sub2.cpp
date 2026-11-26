#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

struct State {
    long long val;
    int cnt;
};

inline State best_state(const State& a, const State& b) {
    if (a.val != b.val) return (a.val > b.val ? a : b);
    return (a.cnt > b.cnt ? a : b);
}

State check_wqs(int n, const vector<long long>& A, long long lambda) {
    State dp0 = {0, 0};
    State dp1 = {-INF, 0};

    for (int i = 0; i < n; ++i) {
        State next_dp0 = best_state(dp0, dp1);
        State next_dp1 = {dp0.val + A[i] - lambda, dp0.cnt + 1};
        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    return best_state(dp0, dp1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("OUTPOST.INP", "r", stdin);
    freopen("OUTPOST.OUT", "w", stdout);

    int n, K;
    cin >> n >> K;

    vector<long long> C(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start_node = 1;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() <= 1) {
            start_node = i;
            break;
        }
    }
    vector<long long> A;
    A.reserve(n);
    int u = start_node, p = 0;
    while (true) {
        A.push_back(C[u]);
        int nxt = 0;
        for (int v : adj[u]) {
            if (v != p) {
                nxt = v;
                break;
            }
        }
        if (nxt == 0) break;
        p = u;
        u = nxt;
    }

    long long low = -4e9, high = 4e9;
    long long best_lambda = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        State res = check_wqs(n, A, mid);

        if (res.cnt >= K) {
            best_lambda = mid;
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    State res = check_wqs(n, A, best_lambda);
    long long ans = res.val + (long long)K * best_lambda;

    cout << ans << "\n";

    return 0;
}