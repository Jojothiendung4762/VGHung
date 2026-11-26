/*
 * Bài 2 - CỬA HÀNG TRANG SỨC (JEWEL)
 * Subtask 3 (100%): N, M <= 2*10^5, thời điểm <= 10^6
 *
 * Ý tưởng (đếm phần bù): khách i KHÔNG mua trong phương án [S, T] khi và chỉ khi
 *   - khách về trước khi mở cửa:  R_i < S, hoặc
 *   - khách đến sau khi đóng cửa: L_i > T.
 * Hai trường hợp này không thể xảy ra cùng lúc (vì L_i <= R_i và S <= T).
 * Vậy  đáp án = TONG - (tổng C_i có R_i < S) - (tổng C_i có L_i > T).
 *
 * Tổ chức dữ liệu (thời điểm <= 10^6 nên dùng mảng đếm phân phối):
 *   byR[t] = tổng C_i có R_i = t, lấy tổng tiền tố  -> preR[t] = tổng C_i có R_i <= t
 *   byL[t] = tổng C_i có L_i = t, lấy tổng tiền tố  -> preL[t] = tổng C_i có L_i <= t
 *   (tổng C_i có L_i > T) = TONG - preL[T].
 * Lưu ý: đáp án có thể tới 2*10^14, dùng long long.
 * Độ phức tạp: O(N + M + MAXT).
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1000000;
long long preR[MAXT + 1], preL[MAXT + 1];

int main() {
    freopen("JEWEL.INP", "r", stdin);
    freopen("JEWEL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        long long c;
        cin >> l >> r >> c;
        preR[r] += c;
        preL[l] += c;
        total += c;
    }
    for (int t = 1; t <= MAXT; t++) {
        preR[t] += preR[t - 1];
        preL[t] += preL[t - 1];
    }

    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
        int s, t;
        cin >> s >> t;
        long long leftEarly = preR[s - 1];          // R_i < S
        long long comeLate  = total - preL[t];      // L_i > T
        cout << total - leftEarly - comeLate << '\n';
    }
    return 0;
}
