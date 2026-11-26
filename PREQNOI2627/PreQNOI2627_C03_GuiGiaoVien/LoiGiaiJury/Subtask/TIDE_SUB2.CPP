/*
 * Bài 4 - THỦY TRIỀU (TIDE)
 * Subtask 2 (20%): mọi câu hỏi có t = 0
 *
 * Ý tưởng: h >= 1 > t nên không lối đi nào bị ngập - đồ thị không đổi.
 *          Hợp mọi lối đi bằng DSU một lần; đáp án = kích thước thành phần chứa u.
 * Độ phức tạp: O((N + M + Q) * α(N)).
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

int main() {
    freopen("TIDE.INP", "r", stdin);
    freopen("TIDE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long h;
        cin >> u >> v >> h;
        dsu.unite(u, v);
    }
    while (q--) {
        int u;
        long long t;
        cin >> u >> t;
        cout << dsu.sizeOf(u) << '\n';
    }
    return 0;
}
