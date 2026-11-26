/*
 * Bai 4 - PRISON, Subtask 2 (N, M <= 2000)
 * Y tuong: dap an la 0 hoac mot muc c[i]. Thu tung nguong X tu nho den lon:
 *          neu do thi chi gom cac cap c > X la do thi hai phia
 *          (to duoc 2 mau bang BFS) thi X la dap an.
 * Do phuc tap: O(M * (N + M)).
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b, c;

// Kiem tra: cac cap co muc thu han > X co chia duoc vao hai trai khac nhau?
bool canSplit(int X) {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
        if (c[i] > X) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
    vector<int> color(n + 1, -1);
    for (int s = 1; s <= n; s++) {
        if (color[s] != -1) continue;
        color[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    freopen("PRISON.INP", "r", stdin);
    freopen("PRISON.OUT", "w", stdout);

    scanf("%d %d", &n, &m);
    a.resize(m); b.resize(m); c.resize(m);
    for (int i = 0; i < m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);

    // Cac nguong can thu: 0 va moi muc c[i], tang dan
    vector<int> cand(c);
    cand.push_back(0);
    sort(cand.begin(), cand.end());

    for (int X : cand)
        if (canSplit(X)) {
            printf("%d\n", X);
            return 0;
        }
    return 0;
}
