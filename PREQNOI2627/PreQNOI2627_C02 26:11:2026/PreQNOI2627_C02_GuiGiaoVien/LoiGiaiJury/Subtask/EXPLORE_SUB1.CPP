// Bai 2 - EXPLORE - Subtask 1 (40%): K = N
// Moi doi can dung 1 hoc sinh tu moi lop => so doi = min(a[i])
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("EXPLORE.INP", "r", stdin);
    freopen("EXPLORE.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    long long ans = LLONG_MAX, x;
    for (int i = 0; i < n; i++) { cin >> x; ans = min(ans, x); }
    cout << ans << "\n";
    return 0;
}
