/*
 * Bài 2 - XẾP HÀNG (LINEUP)
 * Subtask 3 (100%): N <= 10^6
 *
 * Nếu chọn bạn thứ i làm lớp trưởng thì:
 *   - các bạn đứng bên trái (1..i-1) phải nhìn sang phải  -> bạn nào đang nhìn 'L' phải quay;
 *   - các bạn đứng bên phải (i+1..N) phải nhìn sang trái -> bạn nào đang nhìn 'R' phải quay.
 * cost(i) = (số 'L' trong đoạn 1..i-1) + (số 'R' trong đoạn i+1..N).
 * Dùng mảng tổng tiền tố đếm số 'L' và số 'R' để tính mỗi cost(i) trong O(1).
 * Độ phức tạp: O(N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("LINEUP.INP", "r", stdin);
    freopen("LINEUP.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<int> preL(n + 1, 0), preR(n + 1, 0);   // preL[i] = số 'L' trong s[1..i]
    for (int i = 1; i <= n; i++) {
        preL[i] = preL[i - 1] + (s[i - 1] == 'L');
        preR[i] = preR[i - 1] + (s[i - 1] == 'R');
    }
    int best = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int cost = preL[i - 1] + (preR[n] - preR[i]);
        best = min(best, cost);
    }
    cout << best << '\n';
    return 0;
}
