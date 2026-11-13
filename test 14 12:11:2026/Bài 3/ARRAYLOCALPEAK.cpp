#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("ARRAYLOCALPEAK.INP","r",stdin);
    freopen("ARRAYLOCALPEAK.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> so(n + 1);
    vector<ll> psum(n + 1,0);
    for (int i = 1;i <= n;i++) {
        cin >> so[i];
        psum[i] = psum[i - 1] + so[i]; 
    }
    int dem = 0;
    for (int i = k + 1;i <= n - k;i++) {
        ll strai = psum[i - 1] - psum[i - 1 - k];
        ll sphai = psum[i + k] - psum[i];
        if (so[i] * 2 * k > strai + sphai) dem++;
    }
    cout << dem;
}