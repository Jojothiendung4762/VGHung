#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SEMIAMICABLE.INP","r",stdin);
    freopen("SEMIAMICABLE.OUT","w",stdout);
    int l,r,k,tichmax = 0;
    cin >> l >> r >> k;
    vector<ll> Suoc(r + 1,0);
    vector<vector<int>> tsnt(r + 1);
    for (int i = 1;i <= r / 2;i++) {
        for (int j = i * 2;j <= r;j += i) {
            Suoc[j] += i;
        }
    }
    for (int i = 2;i <= r;i++) {
        if (tsnt[i].empty()) {
            for (int j = i;j <= r;j += i) {
                tsnt[j].push_back(i);
            }
        }
    }
    
    fclose(stdin);
    fclose(stdout);
}