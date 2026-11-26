/*
 * Bài 1 - CHỌN THẺ (CARDS)
 * Subtask 2 (100%): N <= 2*10^5, a_i <= 10^9
 *
 * Ý tưởng: K thẻ được chọn phải cùng chẵn hoặc cùng lẻ.
 *   - Tách các thẻ thành hai nhóm: nhóm chẵn và nhóm lẻ.
 *   - Với mỗi nhóm có ít nhất K thẻ: sắp xếp giảm dần, lấy tổng K thẻ lớn nhất.
 *   - Đáp án là tổng lớn hơn trong hai nhóm; nếu cả hai nhóm đều có ít hơn K thẻ thì ghi -1.
 * Lưu ý: tổng có thể tới 2*10^14, phải dùng long long.
 * Độ phức tạp: O(N log N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("CARDS.INP", "r", stdin);
    freopen("CARDS.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> grp[2];          // grp[0]: thẻ chẵn, grp[1]: thẻ lẻ
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        grp[a % 2].push_back(a);
    }

    long long best = -1;
    for (int t = 0; t < 2; t++) {
        if ((int)grp[t].size() < k) continue;
        sort(grp[t].begin(), grp[t].end(), greater<long long>());
        long long s = 0;
        for (int i = 0; i < k; i++) s += grp[t][i];
        best = max(best, s);
    }

    cout << best << '\n';
    return 0;
}
