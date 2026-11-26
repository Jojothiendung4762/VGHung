/*
 * Bai 4 - PRISON: Giam giu (PreQNOI 2026-2027, Contest 10)
 * Nguon : NOIP 2010 Tieu chuan nang cao (Trung Quoc), Luogu P1525.
 *
 * Y tuong:
 *   - Xet cac cap thu dich theo muc thu han GIAM dan.
 *   - Co gang dat moi cap vao hai trai KHAC nhau, dung DSU co "do lech"
 *     (parity): d[u] = 0 neu u cung trai voi goc, 1 neu khac trai.
 *   - Cap dau tien buoc phai o CUNG trai (tao chu trinh le) chinh la dap an.
 *
 * Do phuc tap: O(M log M) thoi gian, O(N + M) bo nho.
 */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, c;
};

int parent_[100005];
int diff_[100005];          // diff_[u] = 0: cung trai voi cha; 1: khac trai

// Tim goc cua u, dong thoi nen duong va cap nhat diff_[u] so voi goc.
// Viet bang vong lap (khong de quy) de tranh tran ngan xep.
int findRoot(int u) {
    vector<int> path;
    while (parent_[u] != u) {
        path.push_back(u);
        u = parent_[u];
    }
    int root = u;
    // Di nguoc tu dinh gan goc nhat ra ngoai de cong don do lech
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        int v = path[i];
        int p = parent_[v];
        if (p != root) diff_[v] ^= diff_[p];
        parent_[v] = root;
    }
    return root;
}

int main() {
    freopen("PRISON.INP", "r", stdin);
    freopen("PRISON.OUT", "w", stdout);

    // 1. Doc du lieu
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Edge> e(m);
    for (int i = 0; i < m; i++) scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);

    // 2. Sap xep cac cap theo muc thu han giam dan
    sort(e.begin(), e.end(), [](const Edge &x, const Edge &y) { return x.c > y.c; });

    for (int i = 1; i <= n; i++) {
        parent_[i] = i;
        diff_[i] = 0;
    }

    // 3. Lan luot tach tung cap ra hai trai khac nhau
    int answer = 0;
    for (int i = 0; i < m; i++) {
        int ra = findRoot(e[i].a);
        int rb = findRoot(e[i].b);
        if (ra == rb) {
            if (diff_[e[i].a] == diff_[e[i].b]) {   // bat buoc cung trai
                answer = e[i].c;
                break;
            }
        } else {
            // Noi hai nhom sao cho a va b o hai trai khac nhau
            parent_[ra] = rb;
            diff_[ra] = diff_[e[i].a] ^ diff_[e[i].b] ^ 1;
        }
    }

    // 4. Ghi ket qua
    printf("%d\n", answer);
    return 0;
}
