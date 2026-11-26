// BOOKS - Subtask 1: N <= 1000 -> thu moi quyen bat dau, doc den khi het gio. O(N^2)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BOOKS.INP", "r", stdin); freopen("BOOKS.OUT", "w", stdout);
    int n; long long t; cin >> n >> t;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    int best = 0;
    for (int i = 0; i < n; i++) {
        long long s = 0; int cnt = 0;
        for (int j = i; j < n && s + a[j] <= t; j++) { s += a[j]; cnt++; }
        best = max(best, cnt);
    }
    cout << best << "\n";
}
