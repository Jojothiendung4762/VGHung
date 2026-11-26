/*
 * Bai 2 - MARBLES, Subtask 1 (N, M, K_i <= 1000)
 * Y tuong: thu lan luot X = 1, 2, 3, ...; X dau tien du ban chia la dap an.
 * Do phuc tap: O(max K * M).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> k(m);
    for (int i = 0; i < m; i++) scanf("%d", &k[i]);

    for (int X = 1; ; X++) {
        int need = 0;                        // so ban can neu moi ban nhan <= X vien
        for (int i = 0; i < m; i++) need += (k[i] + X - 1) / X;
        if (need <= n) {
            printf("%d\n", X);
            return 0;
        }
    }
}
