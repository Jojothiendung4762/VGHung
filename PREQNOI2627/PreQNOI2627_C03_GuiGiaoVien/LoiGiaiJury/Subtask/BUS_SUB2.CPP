/*
 * Bài 1 - HAI TUYẾN XE BUÝT (BUS)
 * Subtask 2 (100%): R <= 10^18
 *
 * Ý tưởng:
 *   - Số bội của x trong đoạn [L, R] là  R / x - (L - 1) / x.
 *   - Hai tuyến cùng xuất bến tại phút t  <=>  t là bội của BCNN(a, b).
 *   - Nguyên lý bù trừ:  |A ∪ B| = |A| + |B| - |A ∩ B|.
 *   - BCNN(a, b) = a / UCLN(a, b) * b  (chia trước, nhân sau để tránh tràn số).
 * Độ phức tạp: O(log(min(a, b))) để tính UCLN.
 */
#include <bits/stdc++.h>
using namespace std;

long long L, R;

// Số bội của x nằm trong đoạn [L, R]
long long countMultiples(long long x) {
    return R / x - (L - 1) / x;
}

int main() {
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b >> L >> R;

    long long g = __gcd(a, b);              // __gcd của GCC (C++14 chưa có std::gcd)
    long long lcm = a / g * b;            // a, b <= 10^9 nên lcm <= 10^18

    long long both = countMultiples(lcm);
    long long atLeastOne = countMultiples(a) + countMultiples(b) - both;

    cout << both << '\n' << atLeastOne << '\n';
    return 0;
}
