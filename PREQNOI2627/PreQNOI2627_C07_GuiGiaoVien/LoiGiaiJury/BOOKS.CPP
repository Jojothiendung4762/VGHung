// BOOKS - loi giai day du: hai con tro. O(N)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BOOKS.INP", "r", stdin); freopen("BOOKS.OUT", "w", stdout);
    int n; long long t; scanf("%d %lld", &n, &t);
    vector<long long> a(n);
    for (auto &x : a) scanf("%lld", &x);
    long long s = 0; int best = 0, l = 0;
    for (int r = 0; r < n; r++) {
        s += a[r];
        while (s > t) s -= a[l++];
        best = max(best, r - l + 1);
    }
    printf("%d\n", best);
}
