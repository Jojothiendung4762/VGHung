// BOOKS - Subtask 2: moi quyen sach doc het cung so phut a -> ket qua min(N, t / a)
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("BOOKS.INP", "r", stdin); freopen("BOOKS.OUT", "w", stdout);
    int n; long long t, a; scanf("%d %lld %lld", &n, &t, &a);
    printf("%lld\n", min((long long)n, t / a));
}
