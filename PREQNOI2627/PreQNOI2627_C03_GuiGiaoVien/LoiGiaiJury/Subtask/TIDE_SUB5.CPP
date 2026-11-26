/*
 * Bài 4 - THỦY TRIỀU (TIDE)
 * Subtask 5 (100%): N, Q <= 10^5, M <= 2 * 10^5
 *
 * Ý tưởng: XỬ LÝ OFFLINE.
 *   - Khi mực nước GIẢM, chỉ có thêm lối đi khô (không bao giờ mất lối đi).
 *   - Sắp xếp câu hỏi theo t giảm dần, lối đi theo h giảm dần.
 *   - Duyệt câu hỏi: thêm (hợp DSU) mọi lối đi có h > t chưa được thêm,
 *     rồi đáp án = kích thước thành phần chứa u.
 * Độ phức tạp: O(M log M + Q log Q + (N + M) * α(N)).
 */
#include <bits/stdc++.h>
using namespace std;

// Cấu trúc các tập rời nhau (DSU) có lưu kích thước mỗi tập
struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {                                 // nén đường đi
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unite(int a, int b) {                        // hợp theo kích thước
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    int sizeOf(int x) { return sz[find(x)]; }
};

struct Road {
    int u, v;
    long long h;
};

int main() {
    freopen("TIDE.INP", "r", stdin);
    freopen("TIDE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<Road> roads(m);
    for (auto &r : roads) cin >> r.u >> r.v >> r.h;

    vector<int> qu(q);
    vector<long long> qt(q);
    for (int i = 0; i < q; i++) cin >> qu[i] >> qt[i];

    // Lối đi: h giảm dần.  Câu hỏi: t giảm dần.
    sort(roads.begin(), roads.end(), [](const Road &a, const Road &b) { return a.h > b.h; });
    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return qt[a] > qt[b]; });

    DSU dsu(n);
    vector<int> answer(q);
    int added = 0;
    for (int i : order) {
        while (added < m && roads[added].h > qt[i]) {     // lối đi còn khô ở mực nước qt[i]
            dsu.unite(roads[added].u, roads[added].v);
            added++;
        }
        answer[i] = dsu.sizeOf(qu[i]);
    }

    for (int i = 0; i < q; i++) cout << answer[i] << '\n';
    return 0;
}
