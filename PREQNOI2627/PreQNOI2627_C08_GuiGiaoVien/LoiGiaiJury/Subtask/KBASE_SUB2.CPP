// KBASE - Subtask 2: N <= 1e6 -> QHD tuyen tinh. x: tan cung khac 0, y: tan cung bang 0. O(N)
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int main() {
    freopen("KBASE.INP", "r", stdin); freopen("KBASE.OUT", "w", stdout);
    long long n, k; cin >> n >> k;
    long long x = (k - 1) % MOD, y = 0;
    for (long long i = 2; i <= n; i++) {
        long long nx = (x + y) % MOD * ((k - 1) % MOD) % MOD, ny = x;
        x = nx; y = ny;
    }
    cout << (x + y) % MOD << "\n";
}
