/*
 * Bai 2 - SEVENS: Nhom so bay (PreQNOI 2026-2027, Contest 10)
 * Nguon : USACO 2016 January, Silver - Problem 2 "Subsequences Summing to Sevens" (Hoa Ky).
 *
 * Y tuong (tong tien to theo modulo 7):
 *   Dat P[i] = (a[1] + ... + a[i]) mod 7, P[0] = 0.
 *   Doan [l, r] co tong chia het cho 7  <=>  P[r] = P[l - 1].
 *   Voi moi r, muon doan dai nhat thi lay l - 1 la vi tri NHO NHAT co cung so du.
 *   Chi can nho first[d] = vi tri dau tien xuat hien so du d.
 *
 * Do phuc tap: O(N) thoi gian, O(1) bo nho (khong can luu mang a).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SEVENS.INP", "r", stdin);
    freopen("SEVENS.OUT", "w", stdout);

    int n;
    scanf("%d", &n);

    // first[d] = vi tri tien to dau tien co so du d (-1 neu chua gap)
    int first[7];
    for (int d = 0; d < 7; d++) first[d] = -1;
    first[0] = 0;                        // tien to rong P[0] = 0

    int prefix = 0;                      // luon giu trong [0, 6] nen khong tran so
    int best = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        prefix = (prefix + x) % 7;
        if (first[prefix] == -1)
            first[prefix] = i;           // lan dau gap so du nay
        else
            best = max(best, i - first[prefix]);
    }

    printf("%d\n", best);
    return 0;
}
