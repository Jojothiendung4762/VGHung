/*
 * Bai 3 - POSTER, Subtask 1 (N <= 300)
 * Y tuong: nha i KHONG can tam moi neu ton tai j < i co h[j] = h[i]
 *          va moi nha k nam giua (j < k < i) deu co h[k] >= h[i].
 *          Thu moi cap (j, i) va kiem tra truc tiep cac nha o giua.
 * Do phuc tap: O(N^3).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("POSTER.INP", "r", stdin);
    freopen("POSTER.OUT", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        long long width;
        scanf("%lld %lld", &width, &h[i]);
    }

    int posters = n;
    for (int i = 0; i < n; i++) {
        bool extended = false;           // nha i co dung chung tam voi nha ben trai?
        for (int j = 0; j < i && !extended; j++) {
            if (h[j] != h[i]) continue;
            bool allHigher = true;
            for (int k = j + 1; k < i; k++)
                if (h[k] < h[i]) allHigher = false;
            if (allHigher) extended = true;
        }
        if (extended) posters--;
    }

    printf("%d\n", posters);
    return 0;
}
