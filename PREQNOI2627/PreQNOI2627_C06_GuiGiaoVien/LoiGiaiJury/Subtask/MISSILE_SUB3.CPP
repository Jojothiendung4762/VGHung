/*
 * Bài 3 - HỆ THỐNG ĐÁNH CHẶN (MISSILE)
 * Subtask 3 (100%): N <= 2*10^5, h_i <= 10^9
 *
 * Câu 1: số mục tiêu nhiều nhất một hệ thống bắn hạ được
 *        = độ dài dãy con KHÔNG TĂNG dài nhất.
 * Câu 2: số hệ thống ít nhất để bắn hạ tất cả
 *        = độ dài dãy con TĂNG NGHIÊM NGẶT dài nhất (định lý Dilworth:
 *          số dãy không tăng ít nhất phủ dãy = độ dài dãy tăng ngặt dài nhất).
 *
 * Kỹ thuật O(N log N): duy trì mảng tail, tail[k] = phần tử cuối "tốt nhất"
 * của dãy con độ dài k+1.
 *   - Dãy không tăng: tail giảm dần (không ngặt); với h tìm vị trí đầu tiên có
 *     tail[k] < h (upper_bound với greater<>) rồi thay thế/ thêm vào.
 *   - Dãy tăng ngặt: tail tăng ngặt; tìm vị trí đầu tiên tail[k] >= h (lower_bound).
 * Độ phức tạp: O(N log N).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MISSILE.INP", "r", stdin);
    freopen("MISSILE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> h(n);
    for (auto &x : h) cin >> x;

    vector<long long> down, up;   // down: tail của dãy không tăng; up: tail của dãy tăng ngặt
    for (long long x : h) {
        // dãy không tăng: down giảm dần, tìm phần tử đầu tiên < x
        auto it = upper_bound(down.begin(), down.end(), x, greater<long long>());
        if (it == down.end()) down.push_back(x); else *it = x;
        // dãy tăng ngặt: up tăng ngặt, tìm phần tử đầu tiên >= x
        auto jt = lower_bound(up.begin(), up.end(), x);
        if (jt == up.end()) up.push_back(x); else *jt = x;
    }
    cout << down.size() << '\n' << up.size() << '\n';
    return 0;
}
