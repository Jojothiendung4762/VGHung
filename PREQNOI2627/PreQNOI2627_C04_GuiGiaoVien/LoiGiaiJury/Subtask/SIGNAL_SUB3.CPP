/*
 * Bài 3 - TÍN HIỆU (SIGNAL)
 * Subtask 3 (100%): N <= 2 * 10^5, a_i, K < 2^30
 *
 * Ý tưởng: XOR tiền tố + cây Trie nhị phân.
 *   XOR đoạn [l, r] = P[r] xor P[l - 1]. Với mỗi r cần đếm số j < r
 *   có (P[r] xor P[j]) >= K.
 *   Lưu các P[j] trong Trie theo bit từ cao (bit 29) xuống thấp, mỗi nút
 *   lưu số giá trị đi qua nó. Đi xuống Trie theo các bit của K:
 *     - Bit của K là 0: mọi giá trị ở nhánh làm bit XOR bằng 1 đều cho
 *       kết quả > K -> cộng cả nhánh đó; tiếp tục đi theo nhánh làm bit XOR = 0.
 *     - Bit của K là 1: bắt buộc bit XOR = 1, đi theo nhánh đó.
 *   Đi hết 30 bit mà vẫn còn nút -> các giá trị đó có XOR đúng bằng K, cộng thêm.
 * Độ phức tạp: O(N * 30).
 */
#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;
const int MAXNODE = 200005 * (LOG + 1) + 5;

int nxt[MAXNODE][2];
int cntNode[MAXNODE];
int numNode = 1;   // nút 0 là gốc

void insertValue(int x) {
    int u = 0;
    cntNode[u]++;
    for (int b = LOG - 1; b >= 0; b--) {
        int c = (x >> b) & 1;
        if (!nxt[u][c]) nxt[u][c] = numNode++;
        u = nxt[u][c];
        cntNode[u]++;
    }
}

// Đếm số giá trị y trong Trie thỏa (x xor y) >= k
long long countAtLeast(int x, int k) {
    long long res = 0;
    int u = 0;
    for (int b = LOG - 1; b >= 0; b--) {
        int xb = (x >> b) & 1, kb = (k >> b) & 1;
        if (kb == 0) {
            int big = nxt[u][xb ^ 1];          // nhánh cho bit XOR = 1
            if (big) res += cntNode[big];
            u = nxt[u][xb];                    // nhánh cho bit XOR = 0
        } else {
            u = nxt[u][xb ^ 1];                // bắt buộc bit XOR = 1
        }
        if (!u) return res;
    }
    return res + cntNode[u];                   // XOR đúng bằng K
}

int main() {
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    insertValue(0);   // P[0] = 0
    int p = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p ^= x;
        ans += countAtLeast(p, k);
        insertValue(p);
    }

    cout << ans << '\n';
    return 0;
}
