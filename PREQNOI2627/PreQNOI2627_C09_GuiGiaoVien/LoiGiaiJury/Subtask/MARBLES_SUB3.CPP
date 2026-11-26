/*
 * Bai 2 - MARBLES: Chia bi (PreQNOI 2026-2027, Contest 09)
 * Nguon : COCI 2012/2013, Vong 1 - Bai "Ljubomora" (Croatia).
 *
 * Y tuong (tim kiem nhi phan tren dap an):
 *   Neu moi ban nhan khong qua X vien thi mau i can it nhat ceil(K_i / X) ban.
 *   Ham need(X) = tong ceil(K_i / X) giam dan theo X, nen tap cac X hop le
 *   (need(X) <= N) la mot doan [X*, +vo cung). Tim X* bang chat nhi phan.
 *
 * Do phuc tap: O(M log(max K)).
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> k;

// Kiem tra: muc ghen X co thuc hien duoc voi N ban hay khong?
bool feasible(ll X) {
    ll need = 0;                            // tong co the toi 2 * 10^14 -> long long
    for (int i = 0; i < m; i++) {
        need += (k[i] + X - 1) / X;         // ceil(K_i / X)
        if (need > n) return false;         // dung som khi da vuot N
    }
    return true;
}

int main() {
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);

    // 1. Doc du lieu
    scanf("%d %d", &n, &m);
    k.resize(m);
    ll maxK = 1;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &k[i]);
        maxK = max(maxK, k[i]);
    }

    // 2. Chat nhi phan: X = maxK chac chan hop le (vi M <= N)
    ll lo = 1, hi = maxK;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (feasible(mid)) hi = mid;        // mid hop le -> dap an <= mid
        else lo = mid + 1;                  // mid khong hop le -> dap an > mid
    }

    // 3. Ghi ket qua
    printf("%lld\n", lo);
    return 0;
}
