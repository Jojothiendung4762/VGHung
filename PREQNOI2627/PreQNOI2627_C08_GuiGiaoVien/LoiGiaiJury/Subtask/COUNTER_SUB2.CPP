// COUNTER - Subtask 2: cha cua moi dinh co so hieu nho hon -> voi canh (a, b) thi cha la min(a, b);
// cong x vao dinh p roi duyet i = 2..N: c[i] += c[cha(i)]. O(N + Q)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("COUNTER.INP", "r", stdin); freopen("COUNTER.OUT", "w", stdout);
    int n, q; scanf("%d %d", &n, &q);
    vector<int> par(n + 1, 0);
    for (int i = 0; i < n - 1; i++) { int a, b; scanf("%d %d", &a, &b); par[max(a, b)] = min(a, b); }
    vector<long long> c(n + 1, 0);
    for (int i = 0; i < q; i++) { int p; long long x; scanf("%d %lld", &p, &x); c[p] += x; }
    for (int i = 2; i <= n; i++) c[i] += c[par[i]];
    for (int i = 1; i <= n; i++) printf("%lld%c", c[i], i == n ? '\n' : ' ');
}
