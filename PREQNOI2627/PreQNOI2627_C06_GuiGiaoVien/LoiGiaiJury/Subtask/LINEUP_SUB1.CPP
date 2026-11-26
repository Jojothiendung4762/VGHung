/*
 * Bài 2 - XẾP HÀNG (LINEUP)
 * Subtask 1 (40%): N <= 1000
 *
 * Thử lần lượt từng bạn i làm lớp trưởng; với mỗi i duyệt cả hàng để đếm
 * số bạn phải quay: bạn j < i đang nhìn 'L', bạn j > i đang nhìn 'R'.
 * Độ phức tạp: O(N^2).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("LINEUP.INP", "r", stdin);
    freopen("LINEUP.OUT", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cost = 0;
        for (int j = 0; j < n; j++) {
            if (j < i && s[j] == 'L') cost++;
            if (j > i && s[j] == 'R') cost++;
        }
        best = min(best, cost);
    }
    cout << best << '\n';
    return 0;
}
