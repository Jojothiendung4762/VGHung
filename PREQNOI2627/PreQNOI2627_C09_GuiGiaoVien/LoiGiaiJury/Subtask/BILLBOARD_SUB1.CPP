/*
 * Bai 1 - BILLBOARD, Subtask 1 (|toa do| <= 1000)
 * Y tuong: chia mat phang thanh cac o vuong don vi.
 *          To cac o thuoc hai bang, xoa cac o bi xe che, roi dem so o con lai.
 *          O (i, j) la hinh vuong [i, i+1] x [j, j+1]; doi toa do +1000 de chi so khong am.
 * Do phuc tap: O(2000 * 2000).
 */
#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1000;
const int SIZE = 2000;

bool covered[SIZE][SIZE];       // covered[i][j] = o (i, j) thuoc bang va chua bi che

int main() {
    freopen("BILLBOARD.INP", "r", stdin);
    freopen("BILLBOARD.OUT", "w", stdout);

    // 1. Doc du lieu (3 hinh chu nhat), doi goc toa do
    int r[3][4];
    for (int k = 0; k < 3; k++)
        for (int t = 0; t < 4; t++) {
            cin >> r[k][t];
            r[k][t] += OFFSET;
        }

    // 2. To cac o cua hai bang quang cao
    for (int k = 0; k < 2; k++)
        for (int i = r[k][0]; i < r[k][2]; i++)
            for (int j = r[k][1]; j < r[k][3]; j++)
                covered[i][j] = true;

    // 3. Xoa cac o bi xe tai che
    for (int i = r[2][0]; i < r[2][2]; i++)
        for (int j = r[2][1]; j < r[2][3]; j++)
            covered[i][j] = false;

    // 4. Dem va ghi ket qua
    long long answer = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (covered[i][j]) answer++;
    cout << answer << "\n";
    return 0;
}
