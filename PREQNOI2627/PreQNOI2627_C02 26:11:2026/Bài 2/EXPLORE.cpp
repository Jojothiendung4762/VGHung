#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("EXPLORE.INP","r",stdin);
    freopen("EXPLORE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> so(n),psum(n + 1);
    for (auto &i : so) {
        cin >> i;
    }
    sort(so.begin(),so.end());
    for (int i = 1;i <= n;i++) {
        psum[i] = psum[i - 1] + so[i - 1];
    }
    int l = 0,r = psum[n] / k;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        int p = lower_bound(so.begin(),so.end(),mid) - so.begin();
        ll dem = psum[p] + (n - p) * mid;
        if (dem >= mid * k) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l;
}