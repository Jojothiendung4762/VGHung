/*
 * Bài 4 - THỦY TRIỀU (TIDE)
 * Subtask 3 (20%): t chỉ nhận không quá 10 giá trị khác nhau
 *
 * Ý tưởng: gom các câu hỏi theo giá trị t. Với mỗi giá trị t:
 *          dựng DSU từ các lối đi có h > t, trả lời mọi câu hỏi có cùng t.
 * Độ phức tạp: O(K * (N + M) + Q) với K = số giá trị t khác nhau.
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
    map<long long, vector<int>> byLevel;              // mực nước -> danh sách câu hỏi
    for (int i = 0; i < q; i++) {
        cin >> qu[i] >> qt[i];
        byLevel[qt[i]].push_back(i);
    }

    vector<int> answer(q);
    for (auto &level : byLevel) {
        long long t = level.first;
        const vector<int> &ids = level.second;
        DSU dsu(n);
        for (const Road &r : roads)
            if (r.h > t) dsu.unite(r.u, r.v);
        for (int i : ids) answer[i] = dsu.sizeOf(qu[i]);
    }

    for (int i = 0; i < q; i++) cout << answer[i] << '\n';
    return 0;
}
