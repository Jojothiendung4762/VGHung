#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("OUTPOST.INP", "r", stdin);
    freopen("OUTPOST.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    long long max_val = -2e18;

    for (int i = 1; i <= n; ++i) {
        long long c;
        cin >> c;
        max_val = max(max_val, c);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
    }

    cout << max_val << "\n";

    return 0;
}