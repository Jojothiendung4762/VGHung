// GIFTS - Subtask 1: N <= 1000 -> sap xep giam dan; moi mon dat nhat chua dong goi
// tim mon re nhat chua dong goi de ghep cung (tim tuan tu). O(N^2)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("GIFTS.INP", "r", stdin); freopen("GIFTS.OUT", "w", stdout);
    long long W; int n; cin >> W >> n;
    vector<long long> p(n);
    for (auto &x : p) cin >> x;
    sort(p.begin(), p.end(), greater<long long>());
    vector<bool> used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true; ans++;
        for (int j = n - 1; j > i; j--)
            if (!used[j]) { if (p[i] + p[j] <= W) used[j] = true; break; }
    }
    cout << ans << "\n";
}
