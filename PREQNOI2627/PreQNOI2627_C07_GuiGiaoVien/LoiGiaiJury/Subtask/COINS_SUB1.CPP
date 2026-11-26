// COINS - Subtask 1: A, B, C <= 50 -> duyet ca ba loai to tien. O(A*B*C)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("COINS.INP", "r", stdin); freopen("COINS.OUT", "w", stdout);
    int A, B, C, X; cin >> A >> B >> C >> X;
    int ans = 0;
    for (int a = 0; a <= A; a++)
        for (int b = 0; b <= B; b++)
            for (int c = 0; c <= C; c++)
                if (500 * a + 100 * b + 50 * c == X) ans++;
    cout << ans << "\n";
}
