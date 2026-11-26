/*
 * Bài 1 - CHỌN THẺ (CARDS)
 * Subtask 1 (60%): N <= 1000, a_i <= 10^6
 *
 * Ý tưởng: thử lần lượt "chọn toàn thẻ chẵn" và "chọn toàn thẻ lẻ".
 * Với mỗi nhóm, lặp K lần: mỗi lần tìm thẻ lớn nhất chưa được chọn trong nhóm
 * (duyệt tuần tự), cộng vào tổng rồi đánh dấu đã chọn.
 * Nếu trong một lần không tìm được thẻ nào thì nhóm đó không đủ K thẻ.
 * Độ phức tạp: O(N * K) <= 10^6.
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long best = -1;
    for (int par = 0; par < 2; par++) {
        vector<bool> used(n, false);
        long long s = 0;
        bool ok = true;
        for (int step = 0; step < k; step++) {
            int pos = -1;
            for (int i = 0; i < n; i++)
                if (!used[i] && a[i] % 2 == par && (pos == -1 || a[i] > a[pos])) pos = i;
            if (pos == -1) { ok = false; break; }
            used[pos] = true;
            s += a[pos];
        }
        if (ok) best = max(best, s);
    }

    cout << best << '\n';
    return 0;
}
