/*
 * Bài 1 - HAI TUYẾN XE BUÝT (BUS)
 * Subtask 1 (60%): R <= 10^6
 *
 * Ý tưởng: duyệt từng phút t từ L đến R.
 *   Tuyến 1 xuất bến tại phút t  <=>  t chia hết cho a.
 *   Tuyến 2 xuất bến tại phút t  <=>  t chia hết cho b.
 * Độ phức tạp: O(R - L + 1).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, L, R;
    cin >> a >> b >> L >> R;

    long long both = 0;      // số phút cả hai tuyến cùng xuất bến
    long long atLeastOne = 0; // số phút có ít nhất một tuyến xuất bến

    for (long long t = L; t <= R; t++) {
        bool bus1 = (t % a == 0);
        bool bus2 = (t % b == 0);
        if (bus1 && bus2) both++;
        if (bus1 || bus2) atLeastOne++;
    }

    cout << both << '\n' << atLeastOne << '\n';
    return 0;
}
