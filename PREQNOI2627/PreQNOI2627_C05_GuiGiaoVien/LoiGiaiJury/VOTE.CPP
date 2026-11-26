/*
 * Bài 3 - BẦU CHỌN (VOTE)
 * Subtask 3 (100%): N <= 12, Q <= 2*10^5
 *
 * Ý tưởng: quá trình rút gọn tạo thành một CÂY TAM PHÂN ĐẦY ĐỦ độ sâu N:
 *   - Tầng 0 là 3^N lá (ý kiến của từng học sinh).
 *   - Phần tử j của tầng h+1 là "đa số" của ba phần tử 3j, 3j+1, 3j+2 của tầng h.
 *   - Gốc (tầng N) là kết quả cuối cùng.
 * Khi một học sinh p đổi ý, chỉ các phần tử trên đường từ lá p lên gốc thay đổi:
 * ở mỗi tầng chỉ số giảm theo j = j / 3. Ta tính lại đúng N phần tử đó.
 *
 * Tổ chức dữ liệu: lv[h] là mảng của tầng h (lưu 1 nếu 'A', 0 nếu 'B'),
 * giống cách cài đặt cây phân đoạn (segment tree) với phép gộp "đa số".
 * Độ phức tạp: xây cây O(3^N), mỗi truy vấn O(N), tổng O(3^N + Q*N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("VOTE.INP", "r", stdin);
    freopen("VOTE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<vector<int> > lv(n + 1);
    lv[0].resize(s.size());
    for (size_t i = 0; i < s.size(); i++) lv[0][i] = (s[i] == 'A');
    for (int h = 0; h < n; h++) {
        int sz = lv[h].size() / 3;
        lv[h + 1].resize(sz);
        for (int j = 0; j < sz; j++)
            lv[h + 1][j] = (lv[h][3 * j] + lv[h][3 * j + 1] + lv[h][3 * j + 2] >= 2);
    }

    string out;
    for (int k = 0; k < q; k++) {
        int p;
        cin >> p;
        int j = p - 1;
        lv[0][j] ^= 1;                        // học sinh p đổi ý
        for (int h = 0; h < n; h++) {         // cập nhật các tổ tiên
            j /= 3;
            lv[h + 1][j] = (lv[h][3 * j] + lv[h][3 * j + 1] + lv[h][3 * j + 2] >= 2);
        }
        out += (lv[n][0] ? 'A' : 'B');
        out += '\n';
    }
    cout << out;
    return 0;
}
