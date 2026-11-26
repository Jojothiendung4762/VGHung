/*
 * Bài 3 - HỆ THỐNG ĐÁNH CHẶN (MISSILE)
 * Subtask 1 (40%): N <= 1000
 *
 * Câu 1: quy hoạch động f[i] = số mục tiêu nhiều nhất bắn được nếu mục tiêu
 *        cuối cùng bị bắn là i:  f[i] = 1 + max{ f[j] : j < i, h[j] >= h[i] }.
 * Câu 2: tham lam. Lần lượt xét từng mục tiêu; giao cho hệ thống có độ cao lần
 *        bắn gần nhất >= h[i] và NHỎ NHẤT trong các hệ thống như vậy; nếu không
 *        có hệ thống nào bắn được thì phải dùng thêm một hệ thống mới.
 * Độ phức tạp: O(N^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MISSILE.INP", "r", stdin);
    freopen("MISSILE.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<long long> h(n);
    for (auto &x : h) cin >> x;

    vector<int> f(n, 1);
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (h[j] >= h[i]) f[i] = max(f[i], f[j] + 1);
        best = max(best, f[i]);
    }

    vector<long long> last;           // độ cao lần bắn gần nhất của từng hệ thống
    for (int i = 0; i < n; i++) {
        int pick = -1;
        for (int k = 0; k < (int)last.size(); k++)
            if (last[k] >= h[i] && (pick == -1 || last[k] < last[pick])) pick = k;
        if (pick == -1) last.push_back(h[i]);
        else last[pick] = h[i];
    }
    cout << best << '\n' << last.size() << '\n';
    return 0;
}
