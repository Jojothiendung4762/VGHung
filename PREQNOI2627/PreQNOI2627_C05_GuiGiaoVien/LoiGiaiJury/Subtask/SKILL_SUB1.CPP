/*
 * Bài 4 - HỌC KỸ NĂNG (SKILL)
 * Subtask 1 (30%): N <= 1000
 *
 * Ý tưởng: với mỗi kỹ năng i (xét từ N về 1), đi ngược theo chuỗi tiền đề
 * i -> P_i -> P_{P_i} -> ... và cộng dồn chi phí cho tới khi gặp P = -1.
 * Chuỗi hợp lệ có không quá N kỹ năng; nếu đã đi quá N bước mà chưa gặp -1
 * thì chuỗi đã rơi vào chu trình -> không học được i.
 * Kỹ năng i đầu tiên (lớn nhất) có tổng chi phí <= X là đáp án.
 * Độ phức tạp: O(N^2).
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

    int ans = -1;
    for (int i = n; i >= 1 && ans == -1; i--) {
        long long cost = 0;
        int u = i, steps = 0;
        bool ok = false;
        while (steps <= n) {
            cost += a[u];
            steps++;
            if (p[u] == -1) { ok = true; break; }
            u = p[u];
        }
        if (ok && cost <= x) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
