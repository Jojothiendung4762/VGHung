/*
 * Bai 1 - DIGITS, Subtask 1 (N <= 10^6)
 * Y tuong: voi moi so i tu 1 den N, dem so chu so bang cach chia lien tiep cho 10.
 * Do phuc tap: O(N * so chu so).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);

    long long n;
    cin >> n;

    long long answer = 0;
    for (long long i = 1; i <= n; i++) {
        long long x = i;
        while (x > 0) {                  // moi lan chia 10 la bot mot chu so
            answer++;
            x /= 10;
        }
    }

    cout << answer << "\n";
    return 0;
}
