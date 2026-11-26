/*
 * Bai 3 - SCORE: Tro choi tinh diem (PreQNOI 2026-2027, Contest 09)
 * Nguon : Codeforces Round 260 - Bai 455A "Boredom" (Nga).
 *
 * Y tuong (quy hoach dong tren cac gia tri khac nhau):
 *   - Neu da chon gia tri v thi nen lay HET cac phan tu bang v, duoc v * cnt[v] diem,
 *     va khong the chon v - 1, v + 1. Bai toan tro thanh: chon mot tap gia tri
 *     khong co hai gia tri hon kem nhau 1 de tong diem lon nhat.
 *   - Sap xep, gom cac gia tri bang nhau: v[1] < v[2] < ... < v[k], s[j] = v[j] * cnt.
 *   - f[j] = diem lon nhat khi chi xet j gia tri dau.
 *       + Neu v[j] = v[j-1] + 1: f[j] = max(f[j-1], f[j-2] + s[j]).
 *       + Nguoc lai:             f[j] = f[j-1] + s[j].
 *   a_i toi 10^9 nen khong lap mang theo gia tri ma lam tren cac gia tri da nen.
 *
 * Do phuc tap: O(n log n). Dap an toi 10^14 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("SCORE.INP", "r", stdin);
    freopen("SCORE.OUT", "w", stdout);

    // 1. Doc du lieu va sap xep
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a.begin(), a.end());

    // 2. Gom cac gia tri bang nhau
    vector<ll> value, gain;            // gain[j] = tong diem neu chon gia tri value[j]
    for (int i = 0; i < n; i++) {
        if (value.empty() || value.back() != a[i]) {
            value.push_back(a[i]);
            gain.push_back(0);
        }
        gain.back() += a[i];
    }
    int k = value.size();

    // 3. Quy hoach dong; f[0] = 0 (chua xet gia tri nao)
    vector<ll> f(k + 1, 0);
    for (int j = 1; j <= k; j++) {
        bool adjacent = (j >= 2 && value[j - 1] == value[j - 2] + 1);
        if (adjacent)
            f[j] = max(f[j - 1], f[j - 2] + gain[j - 1]);   // bo gia tri j, hoac chon no va bo j-1
        else
            f[j] = f[j - 1] + gain[j - 1];                   // chon duoc ca gia tri j
    }

    // 4. Ghi ket qua
    printf("%lld\n", f[k]);
    return 0;
}
