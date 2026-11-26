// KBASE - loi giai day du: QHD trang thai (tan cung khac 0, tan cung bang 0) + luy thua ma tran 2x2. O(log N)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
const ll MOD = 1000000007LL;
typedef array<array<ll,2>,2> Mat;
Mat mul(const Mat &a, const Mat &b) {
    Mat c{};
    for (int i = 0; i < 2; i++) for (int k = 0; k < 2; k++) for (int j = 0; j < 2; j++)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}
int main() {
    freopen("KBASE.INP", "r", stdin); freopen("KBASE.OUT", "w", stdout);
    ll n, k; cin >> n >> k;
    ll q = (k - 1) % MOD;
    // [x_{i+1}]   [q q] [x_i]     x_i: so cach co i chu so, tan cung khac 0
    // [y_{i+1}] = [1 0] [y_i]     y_i: so cach co i chu so, tan cung bang 0
    Mat M = {{{q, q}, {1, 0}}}, R = {{{1, 0}, {0, 1}}};
    ll e = n - 1;
    while (e > 0) { if (e & 1) R = mul(R, M); M = mul(M, M); e >>= 1; }
    ll x = R[0][0] * q % MOD, y = R[1][0] * q % MOD;   // (x_1, y_1) = (K-1, 0)
    cout << (x + y) % MOD << "\n";
}
