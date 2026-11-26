#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("OUTPOST.INP", "r", stdin);
    freopen("OUTPOST.OUT", "w", stdout);

    int n, K;
    cin >> n >> K;

    vector<long long> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u - 1, v - 1});
    }

    long long max_importance = -INF;
    int total_masks = (1 << n);

    for (int mask = 0; mask < total_masks; ++mask) {
        if (__builtin_popcount(mask) != K) continue;
        bool valid = true;
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            if (((mask >> u) & 1) && ((mask >> v) & 1)) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;
        long long current_sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                current_sum += C[i];
            }
        }

        max_importance = max(max_importance, current_sum);
    }

    cout << max_importance << "\n";

    return 0;
}