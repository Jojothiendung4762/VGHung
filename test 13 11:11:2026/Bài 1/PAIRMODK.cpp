#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("PAIRMODK.INP","r",stdin);
    freopen("PAIRMODK.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d,k,dem = 0;
    cin >> n >> d >> k;
    vector<int> so(n);
    for (auto &i : so) {
        cin >> i;
    }
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            if (j - i >= d && (so[i] + so[j]) % k == 0) dem++;
        }
    }
    cout << dem;
}