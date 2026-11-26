/*
 * Bai 1 - BILLBOARD: Bang quang cao (PreQNOI 2026-2027, Contest 09)
 * Nguon : USACO 2017 December, Bronze - Problem 1 "Blocked Billboard" (Hoa Ky).
 *
 * Y tuong:
 *   Phan nhin thay cua moi bang = dien tich bang - dien tich phan bi xe tai che.
 *   Phan chung cua hai hinh chu nhat canh song song truc toa do cung la
 *   mot hinh chu nhat: rong = min(phai) - max(trai), cao = min(tren) - max(duoi).
 *   Neu rong <= 0 hoac cao <= 0 thi hai hinh khong giao nhau.
 *
 * Do phuc tap: O(1). Dap an toi 8 * 10^18 nen dung long long.
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Rect {
    ll x1, y1, x2, y2;          // (x1, y1): goc trai duoi; (x2, y2): goc phai tren
};

ll area(const Rect &r) {
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}

// Dien tich phan chung cua hai hinh chu nhat (bang 0 neu khong giao nhau)
ll intersectArea(const Rect &a, const Rect &b) {
    ll w = min(a.x2, b.x2) - max(a.x1, b.x1);
    ll h = min(a.y2, b.y2) - max(a.y1, b.y1);
    if (w <= 0 || h <= 0) return 0;
    return w * h;
}

int main() {
    freopen("BILLBOARD.INP", "r", stdin);
    freopen("BILLBOARD.OUT", "w", stdout);

    // 1. Doc du lieu: hai bang quang cao va xe tai
    Rect board1, board2, truck;
    cin >> board1.x1 >> board1.y1 >> board1.x2 >> board1.y2;
    cin >> board2.x1 >> board2.y1 >> board2.x2 >> board2.y2;
    cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;

    // 2. Tinh phan nhin thay cua tung bang
    ll visible1 = area(board1) - intersectArea(board1, truck);
    ll visible2 = area(board2) - intersectArea(board2, truck);

    // 3. Ghi ket qua
    cout << visible1 + visible2 << "\n";
    return 0;
}
