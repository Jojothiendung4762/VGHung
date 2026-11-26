/*
 * Bai 3 - SCORE, Subtask 1 (n <= 20)
 * Y tuong: co toi da 20 gia tri khac nhau -> thu moi tap con cac gia tri,
 *          bo qua tap chua hai gia tri hon kem nhau 1, lay tong diem lon nhat.
 * Do phuc tap: O(2^k * n), k = so gia tri khac nhau.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("SCORE.INP", "r", stdin);
    freopen("SCORE.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Danh sach cac gia tri khac nhau, tang dan
    vector<ll> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int k = v.size();

    ll best = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        // Kiem tra tap hop le: khong chon hai gia tri lien tiep hon kem nhau 1
        bool valid = true;
        for (int i = 0; i + 1 < k; i++)
            if ((mask >> i & 1) && (mask >> (i + 1) & 1) && v[i + 1] == v[i] + 1)
                valid = false;
        if (!valid) continue;

        // Tong diem: lay moi phan tu co gia tri duoc chon
        ll total = 0;
        for (int i = 0; i < k; i++)
            if (mask >> i & 1)
                for (int t = 0; t < n; t++)
                    if (a[t] == v[i]) total += a[t];
        best = max(best, total);
    }

    cout << best << "\n";
    return 0;
}
