/*
 * Bai 2 - MARBLES, Subtask 2 (moi K_i bang nhau, bang K)
 * Y tuong: chia deu ban cho cac mau. Mau nao cung co it nhat q = N div M ban,
 *          va de muc ghen nho nhat thi moi mau nen nhan dung q ban (phan du khong giup gi
 *          cho mau it ban nhat). Vay dap an = ceil(K / q).
 *          Kiem tra: M * ceil(K / X) <= N  <=>  ceil(K / X) <= q  <=>  X >= K / q.
 * Do phuc tap: O(M) (chi de doc du lieu).
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);

    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll K = 0;
    for (int i = 0; i < m; i++) scanf("%lld", &K);   // moi K_i deu bang K

    ll q = n / m;                        // so ban moi mau duoc nhan
    printf("%lld\n", (K + q - 1) / q);
    return 0;
}
