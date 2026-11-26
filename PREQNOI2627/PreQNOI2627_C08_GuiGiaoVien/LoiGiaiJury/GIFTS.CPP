// GIFTS - loi giai day du: sap xep, ghep mon dat nhat voi mon re nhat neu duoc (hai con tro). O(N log N)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("GIFTS.INP", "r", stdin); freopen("GIFTS.OUT", "w", stdout);
    long long W; int n; scanf("%lld %d", &W, &n);
    vector<long long> p(n);
    for (auto &x : p) scanf("%lld", &x);
    sort(p.begin(), p.end());
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (i < j && p[i] + p[j] <= W) i++;   // mon re nhat di cung mon dat nhat
        j--; ans++;
    }
    printf("%d\n", ans);
}
