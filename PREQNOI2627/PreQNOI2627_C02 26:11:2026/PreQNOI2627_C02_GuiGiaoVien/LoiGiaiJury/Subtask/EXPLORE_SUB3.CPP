// Bai 2 - EXPLORE - Subtask 3 (100%): tim kiem nhi phan theo dap an
// Lap duoc P doi  <=>  sum(min(a[i], P)) >= K * P
// (moi lop gop toi da 1 hoc sinh cho moi doi, nen toi da min(a[i], P) hoc sinh;
//  neu tong >= K*P thi xep vong tron vao P doi la duoc)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> a;

bool ok(ll P) {
    ll s = 0;
    for (int i = 0; i < n; i++) s += min(a[i], P);
    return s >= (ll)k * P;                  // P <= S/K nen K*P <= 1e14, khong tran
}

int main() {
    freopen("EXPLORE.INP", "r", stdin);
    freopen("EXPLORE.OUT", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    ll S = 0;
    for (auto &x : a) { cin >> x; S += x; }
    ll lo = 0, hi = S / k;                  // dap an khong vuot qua S/K
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid; else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
