#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("FUND.INP", "r", stdin);
    freopen("FUND.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, y;
    cin >> n >> x >> y;

    long long total = 0;

    for (long long i = 1; i <= n; ++i) {
        total += x;
        if (i % 3 == 0) {
            total += y;
        }
    }

    cout << total << "\n";

    return 0;
}