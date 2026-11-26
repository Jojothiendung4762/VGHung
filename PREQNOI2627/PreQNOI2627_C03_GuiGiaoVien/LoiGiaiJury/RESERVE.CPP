/*
 * Bài 3 - KHU BẢO TỒN (RESERVE)
 * Subtask 3 (100%): N, Q <= 10^5
 *
 * Ý tưởng:
 *   1) Bao lồi bằng thuật toán Andrew (monotone chain):                 O(N log N)
 *        - sắp xếp điểm theo (x, y);
 *        - dựng nửa dưới và nửa trên bằng "ngăn xếp", bỏ điểm làm rẽ phải
 *          hoặc thẳng hàng (để bao lồi không có 3 đỉnh thẳng hàng).
 *   2) Diện tích và vị trí từng cây: như Subtask 2.                     O(log N) mỗi cây
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

vector<Point> convexHullAndrew(vector<Point> pts) {
    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    int n = pts.size(), k = 0;
    vector<Point> hull(2 * n);
    for (int i = 0; i < n; i++) {                              // nửa dưới
        while (k >= 2 && orient(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    for (int i = n - 2, lower = k + 1; i >= 0; i--) {         // nửa trên
        while (k >= lower && orient(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    hull.resize(k - 1);                                        // điểm cuối trùng điểm đầu
    return hull;                                               // ngược chiều kim đồng hồ
}

int main() {
    freopen("RESERVE.INP", "r", stdin);
    freopen("RESERVE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;

    vector<Point> hull = convexHullAndrew(pts);
    int h = hull.size();

    ll doubleArea = 0;
    for (int i = 1; i + 1 < h; i++)
        doubleArea += cross(hull[i] - hull[0], hull[i + 1] - hull[0]);
    cout << doubleArea << '\n';

    const char *answer[] = {"OUT", "ON", "IN"};
    int q;
    cin >> q;
    while (q--) {
        Point t;
        cin >> t.x >> t.y;
        cout << answer[locate(hull, t) + 1] << '\n';
    }
    return 0;
}
