#include <iostream>
#include <vector>
using namespace std;
using str = string;

int main() {
    freopen("PALINDIVISIBLE.INP","r",stdin);
    freopen("PALINDIVISIBLE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    str s;
    cin >> n >> k >> s;
    vector<int> ps(n + 1);
    ps[0] = 0;
    for (int i = 0;i < n;i++) {
        ps[i + 1] = ps[i] + (int)s[i];
    }
    int kq = 0;
    
}