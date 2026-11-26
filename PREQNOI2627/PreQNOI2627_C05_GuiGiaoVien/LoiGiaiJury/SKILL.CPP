/*
 * Bài 4 - HỌC KỸ NĂNG (SKILL)
 * Subtask 3 (100%): N <= 2*10^5, không có ràng buộc gì thêm
 *
 * Ý tưởng: muốn học kỹ năng i phải học trước P_i, muốn học P_i phải học trước P_{P_i}, ...
 * cho tới một kỹ năng không cần điều kiện (P = -1). Vậy tập kỹ năng ÍT NHẤT phải học
 * để học được i chính là "chuỗi tiền đề" từ gốc tới i, và i học được khi và chỉ khi
 *       S[i] = A[i] + S[P[i]]  <=  X      (S[gốc] = A[gốc]).
 * Nếu chuỗi tiền đề của i đi vào một chu trình thì không bao giờ học được i.
 *
 * Mô hình đồ thị: nối cạnh có hướng P_i -> i. Các đỉnh có P = -1 là gốc,
 * những đỉnh đi tới được từ các gốc tạo thành một RỪNG; các đỉnh nằm trên
 * hoặc "treo" dưới chu trình thì không đi tới được từ gốc nào.
 * => BFS từ tất cả các gốc, tính S theo thứ tự duyệt; đỉnh không được thăm thì bỏ qua.
 * Đáp án: chỉ số i lớn nhất được thăm có S[i] <= X, hoặc -1.
 * Lưu ý: S có thể tới 2*10^14, dùng long long.
 * Độ phức tạp: O(N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SKILL.INP", "r", stdin);
    freopen("SKILL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<int> > child(n + 1);
    queue<int> qu;
    vector<long long> S(n + 1, -1);       // -1: chưa thăm (không học được)
    for (int i = 1; i <= n; i++) {
        if (p[i] == -1) { S[i] = a[i]; qu.push(i); }
        else child[p[i]].push_back(i);
    }
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (size_t t = 0; t < child[u].size(); t++) {
            int v = child[u][t];
            S[v] = S[u] + a[v];
            qu.push(v);
        }
    }

    int ans = -1;
    for (int i = n; i >= 1; i--)
        if (S[i] != -1 && S[i] <= x) { ans = i; break; }
    cout << ans << '\n';
    return 0;
}
