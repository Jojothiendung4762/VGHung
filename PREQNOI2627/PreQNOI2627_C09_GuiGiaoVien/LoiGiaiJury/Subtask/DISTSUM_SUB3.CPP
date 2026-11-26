/*
 * Bai 4 - DISTSUM: Tong khoang cach (PreQNOI 2026-2027, Contest 09)
 * Nguon : AtCoder Beginner Contest 220 - Bai F "Distance Sums 2" (Nhat Ban).
 *
 * Y tuong (doi goc - rerooting):
 *   - Chon dinh 1 lam goc. Tinh do sau dep[] va kich thuoc cay con sz[].
 *     ans[1] = tong do sau cua moi dinh.
 *   - Khi chuyen tu dinh u sang con v: sz[v] dinh (trong cay con v) gan them 1,
 *     n - sz[v] dinh con lai xa them 1. Vay ans[v] = ans[u] + n - 2 * sz[v].
 *   - Duyet bang BFS (khong de quy) de tranh tran ngan xep khi cay sau 2 * 10^5.
 *
 * Do phuc tap: O(N). Dap an toi khoang 2 * 10^10 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("DISTSUM.INP", "r", stdin);
    freopen("DISTSUM.OUT", "w", stdout);

    // 1. Doc cay
    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. BFS tu dinh 1: thu tu duyet, cha, do sau
    vector<int> order, parent(n + 1, 0);
    vector<ll> depth(n + 1, 0), sz(n + 1, 1), ans(n + 1, 0);
    order.reserve(n);
    order.push_back(1);
    parent[1] = 0;
    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for (int v : adj[u])
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
    }

    // 3. Kich thuoc cay con: duyet nguoc thu tu BFS (con truoc, cha sau)
    for (int i = n - 1; i >= 1; i--) {
        int v = order[i];
        sz[parent[v]] += sz[v];
    }

    // 4. Dap an cho goc, roi doi goc theo thu tu BFS (cha truoc, con sau)
    for (int v = 1; v <= n; v++) ans[1] += depth[v];
    for (int i = 1; i < n; i++) {
        int v = order[i];
        ans[v] = ans[parent[v]] + n - 2 * sz[v];
    }

    // 5. Ghi ket qua tren mot dong
    for (int v = 1; v <= n; v++) printf("%lld%c", ans[v], v == n ? '\n' : ' ');
    return 0;
}
