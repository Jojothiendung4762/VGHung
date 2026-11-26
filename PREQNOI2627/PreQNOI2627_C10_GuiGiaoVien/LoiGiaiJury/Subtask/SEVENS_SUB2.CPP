/*
 * Bai 2 - SEVENS, Subtask 2 (N <= 5000)
 * Y tuong: tong tien to S[i]; tong doan [l, r] = S[r] - S[l - 1]. Thu moi cap (l, r).
 * Do phuc tap: O(N^2). Tong toi 5 * 10^9 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SEVENS.INP", "r", stdin);
    freopen("SEVENS.OUT", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<long long> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        s[i] = s[i - 1] + x;
    }

    int best = 0;
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            if ((s[r] - s[l - 1]) % 7 == 0) best = max(best, r - l + 1);

    printf("%d\n", best);
    return 0;
}
