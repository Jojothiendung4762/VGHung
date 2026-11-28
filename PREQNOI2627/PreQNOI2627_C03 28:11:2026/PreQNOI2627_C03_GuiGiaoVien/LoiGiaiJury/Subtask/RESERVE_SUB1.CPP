/*
 * Bài 3 - KHU BẢO TỒN (RESERVE)
 * Subtask 1 (40%): N, Q <= 300
 *
 * Ý tưởng:
 *   1) Bao lồi bằng thuật toán "gói quà" (Jarvis): bắt đầu từ điểm thấp nhất,
 *      mỗi bước chọn điểm tiếp theo sao cho mọi điểm khác nằm bên trái.  O(N * h)
 *   2) Diện tích: chia đa giác thành các tam giác chung đỉnh hull[0].
 *   3) Mỗi cây: kiểm tra với TỪNG cạnh của bao lồi (đi ngược chiều kim đồng hồ):
 *        có cạnh để cây ở bên phải   -> OUT
 *        mọi cạnh để cây ở bên trái  -> IN
 *        còn lại (nằm trên một cạnh) -> ON                              O(h) mỗi cây
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

vector<Point> convexHullJarvis(vector<Point> pts) {
    int n = pts.size();
    int start = 0;                                   // điểm thấp nhất (rồi trái nhất)
    for (int i = 1; i < n; i++)
        if (pts[i].y < pts[start].y || (pts[i].y == pts[start].y && pts[i].x < pts[start].x))
            start = i;

    auto same = [](Point a, Point b) { return a.x == b.x && a.y == b.y; };
    vector<Point> hull;
    int cur = start;
    do {
        hull.push_back(pts[cur]);
        int nxt = -1;
        for (int i = 0; i < n; i++) {
            if (same(pts[i], pts[cur])) continue;          // bỏ qua điểm trùng
            if (nxt == -1) { nxt = i; continue; }
            ll o = orient(pts[cur], pts[nxt], pts[i]);
            // chọn điểm "bên phải nhất"; nếu thẳng hàng thì chọn điểm xa hơn
            if (o < 0 || (o == 0 && onSegment(pts[cur], pts[i], pts[nxt])))
                nxt = i;
        }
        cur = nxt;
    } while (!same(pts[cur], pts[start]));
    return hull;
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

    vector<Point> hull = convexHullJarvis(pts);
    int h = hull.size();

    ll doubleArea = 0;
    for (int i = 1; i + 1 < h; i++)
        doubleArea += cross(hull[i] - hull[0], hull[i + 1] - hull[0]);
    cout << doubleArea << '\n';

    int q;
    cin >> q;
    while (q--) {
        Point t;
        cin >> t.x >> t.y;
        bool outside = false, onEdge = false;
        for (int i = 0; i < h; i++) {
            ll o = orient(hull[i], hull[(i + 1) % h], t);
            if (o < 0) outside = true;
            else if (o == 0) onEdge = true;
        }
        if (outside)     cout << "OUT\n";
        else if (onEdge) cout << "ON\n";
        else             cout << "IN\n";
    }
    return 0;
}
