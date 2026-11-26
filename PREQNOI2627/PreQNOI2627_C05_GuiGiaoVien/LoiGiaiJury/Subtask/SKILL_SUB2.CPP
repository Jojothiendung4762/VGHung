/*
 * Bài 4 - HỌC KỸ NĂNG (SKILL)
 * Subtask 2 (30%): P_i < i với mọi i có P_i != -1
 *
 * Ý tưởng: tiền đề luôn có số hiệu nhỏ hơn nên không có chu trình, và khi xét i
 * theo thứ tự tăng dần thì S[P_i] đã được tính xong (quy hoạch động trên cây):
 *       S[i] = A[i]            nếu P_i = -1
 *       S[i] = A[i] + S[P_i]   nếu ngược lại.
 * Đáp án là i lớn nhất có S[i] <= X, hoặc -1.
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
    vector<long long> a(n + 1), S(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        S[i] = a[i] + (p[i] == -1 ? 0 : S[p[i]]);
        if (S[i] <= x) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
