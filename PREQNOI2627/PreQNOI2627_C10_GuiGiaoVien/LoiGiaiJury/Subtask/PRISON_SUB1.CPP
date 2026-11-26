/*
 * Bai 4 - PRISON, Subtask 1 (N <= 15, M <= 100)
 * Y tuong: thu moi cach chia N tu nhan vao hai trai (2^N cach),
 *          voi moi cach tinh muc thu han lon nhat trong cung mot trai.
 * Do phuc tap: O(2^N * M).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("PRISON.INP", "r", stdin);
    freopen("PRISON.OUT", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);

    int best = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {      // bit i = trai cua tu nhan i + 1
        int worst = 0;
        for (int i = 0; i < m; i++) {
            int ta = (mask >> (a[i] - 1)) & 1;
            int tb = (mask >> (b[i] - 1)) & 1;
            if (ta == tb) worst = max(worst, c[i]);
        }
        best = min(best, worst);
    }

    printf("%d\n", best);
    return 0;
}
