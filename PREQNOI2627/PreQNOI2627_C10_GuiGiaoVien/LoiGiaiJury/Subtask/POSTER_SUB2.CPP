/*
 * Bai 3 - POSTER, Subtask 2 (N <= 5000)
 * Y tuong: tu nha i di nguoc sang trai.
 *          Gap nha thap hon h[i] -> dung (tam khong the vuot qua);
 *          gap nha bang h[i] -> nha i dung chung tam voi nha do.
 * Do phuc tap: O(N^2).
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
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0; j--) {
            if (h[j] < h[i]) break;
            if (h[j] == h[i]) {
                posters--;
                break;
            }
        }

    printf("%d\n", posters);
    return 0;
}
