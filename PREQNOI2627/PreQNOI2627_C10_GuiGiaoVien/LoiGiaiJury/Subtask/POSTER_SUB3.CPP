/*
 * Bai 3 - POSTER: Dan ap phich (PreQNOI 2026-2027, Contest 10)
 * Nguon : Olympic Tin hoc Ba Lan lan thu XV (2007/2008), Vong 1 - Bai "Plakatowanie".
 *
 * Y tuong (ngan xep don dieu):
 *   - Chieu rong cac ngoi nha khong anh huong den dap an.
 *   - Moi ngoi nha can mot tam ap phich co canh tren dung bang chieu cao cua no,
 *     TRU KHI ben trai co nha j cung chieu cao va moi nha giua j va i deu cao hon:
 *     khi do tam cua j duoc keo dai sang i.
 *   - Duy tri ngan xep cac chieu cao tang dan:
 *       + bo cac chieu cao > h (chung bi nha i "chan" lai);
 *       + neu dinh ngan xep = h thi dung lai tam cu, nguoc lai can tam moi.
 *
 * Do phuc tap: O(N) (moi chieu cao vao va ra ngan xep toi da mot lan).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("POSTER.INP", "r", stdin);
    freopen("POSTER.OUT", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<long long> st;                // ngan xep chieu cao, tang dan tu day len dinh
    st.reserve(n);
    int posters = 0;

    for (int i = 0; i < n; i++) {
        long long width, h;
        scanf("%lld %lld", &width, &h);

        while (!st.empty() && st.back() > h) st.pop_back();

        if (!st.empty() && st.back() == h) continue;   // keo dai tam ap phich cu

        st.push_back(h);                 // can mot tam ap phich moi
        posters++;
    }

    printf("%d\n", posters);
    return 0;
}
