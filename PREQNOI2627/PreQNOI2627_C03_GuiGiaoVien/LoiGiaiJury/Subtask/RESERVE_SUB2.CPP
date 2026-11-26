/*
 * Bài 3 - KHU BẢO TỒN (RESERVE)
 * Subtask 2 (70%): các cột mốc được cho theo thứ tự ngược chiều kim đồng hồ
 *                  và tạo thành một đa giác lồi (không có 3 điểm thẳng hàng).
 *
 * Ý tưởng: không cần dựng bao lồi - đa giác đã có sẵn.
 *   - Diện tích: chia quạt tam giác từ đỉnh 0.                         O(N)
 *   - Mỗi cây: tìm kiếm nhị phân tam giác quạt chứa cây.                O(log N)
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }

// Tích có hướng của hai vectơ u, v:
//   > 0 : v nằm bên TRÁI u (quay ngược chiều kim đồng hồ)
//   = 0 : u, v cùng phương
//   < 0 : v nằm bên PHẢI u
// |toạ độ| <= 1e9 nên mỗi thành phần <= 2e9, kết quả <= 8e18: vừa long long.
ll cross(Point u, Point v) { return u.x * v.y - u.y * v.x; }

// Hướng của c so với đường thẳng a -> b
ll orient(Point a, Point b, Point c) { return cross(b - a, c - a); }

// c nằm trên đoạn [a, b], biết trước a, b, c thẳng hàng
bool onSegment(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// Vị trí của t so với đa giác lồi poly (ngược chiều kim đồng hồ, không có 3 đỉnh thẳng hàng).
// Chia đa giác thành "quạt" tam giác chung đỉnh poly[0], tìm kiếm nhị phân tam giác chứa t.
// Trả về: 1 = IN, 0 = ON, -1 = OUT.                                             O(log N)
int locate(const vector<Point> &poly, Point t) {
    int n = poly.size();
    Point o = poly[0];
    ll first = orient(o, poly[1], t);
    ll last  = orient(o, poly[n - 1], t);
    if (first < 0 || last > 0) return -1;             // ngoài góc quạt
    if (first == 0) return onSegment(o, poly[1], t) ? 0 : -1;
    if (last == 0)  return onSegment(o, poly[n - 1], t) ? 0 : -1;

    // tìm k lớn nhất (1 <= k <= n-2) sao cho t nằm bên trái (hoặc trên) tia o -> poly[k]
    int lo = 1, hi = n - 2;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (orient(o, poly[mid], t) >= 0) lo = mid;
        else hi = mid - 1;
    }
    ll side = orient(poly[lo], poly[lo + 1], t);       // t nằm trong tam giác (o, poly[lo], poly[lo+1])?
    if (side > 0)  return 1;
    if (side == 0) return 0;
    return -1;
}

int main() {
    freopen("RESERVE.INP", "r", stdin);
    freopen("RESERVE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> poly(n);
    for (auto &p : poly) cin >> p.x >> p.y;

    ll doubleArea = 0;
    for (int i = 1; i + 1 < n; i++)
        doubleArea += cross(poly[i] - poly[0], poly[i + 1] - poly[0]);
    cout << doubleArea << '\n';

    const char *answer[] = {"OUT", "ON", "IN"};
    int q;
    cin >> q;
    while (q--) {
        Point t;
        cin >> t.x >> t.y;
        cout << answer[locate(poly, t) + 1] << '\n';
    }
    return 0;
}
