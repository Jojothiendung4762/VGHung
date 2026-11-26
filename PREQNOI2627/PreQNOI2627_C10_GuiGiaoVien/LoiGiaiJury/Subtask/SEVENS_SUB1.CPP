/*
 * Bai 2 - SEVENS, Subtask 1 (N <= 300)
 * Y tuong: thu moi doan [l, r], cong truc tiep cac phan tu roi kiem tra chia het cho 7.
 * Do phuc tap: O(N^3).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SEVENS.INP", "r", stdin);
    freopen("SEVENS.OUT", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    int best = 0;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++) {
            long long sum = 0;
            for (int i = l; i <= r; i++) sum += a[i];
            if (sum % 7 == 0) best = max(best, r - l + 1);
        }

    printf("%d\n", best);
    return 0;
}
