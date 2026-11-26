// Bai 2 - EXPLORE - Subtask 2 (70%): N <= 100, a[i] <= 100
// Tham lam mo phong: moi lan lap 1 doi tu K lop dong nhat con lai
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("EXPLORE.INP", "r", stdin);
    freopen("EXPLORE.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    long long cnt = 0;
    while (true) {
        sort(a.rbegin(), a.rend());          // sap xep giam dan
        if (a[k - 1] == 0) break;            // khong du K lop con hoc sinh
        for (int i = 0; i < k; i++) a[i]--;  // lay moi lop 1 hoc sinh
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
