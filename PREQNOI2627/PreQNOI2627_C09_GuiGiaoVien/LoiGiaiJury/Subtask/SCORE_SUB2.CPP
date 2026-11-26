/*
 * Bai 3 - SCORE, Subtask 2 (a_i <= 10^5)
 * Y tuong: dem cnt[v]; f[v] = diem lon nhat khi chi xet cac gia tri 1..v:
 *          f[v] = max(f[v-1], f[v-2] + v * cnt[v]).
 * Do phuc tap: O(n + max a). Dap an toi 10^10 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 100000;

ll cnt[MAXV + 1];
ll f[MAXV + 1];

int main() {
    freopen("SCORE.INP", "r", stdin);
    freopen("SCORE.OUT", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    f[0] = 0;
    f[1] = cnt[1];
    for (int v = 2; v <= MAXV; v++)
        f[v] = max(f[v - 1], f[v - 2] + cnt[v] * v);

    printf("%lld\n", f[MAXV]);
    return 0;
}
