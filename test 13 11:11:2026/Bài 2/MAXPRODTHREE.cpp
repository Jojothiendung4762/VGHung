#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

struct abc {
    vector<int> duong;
    vector<int> am;
};

int main() {
    freopen("MAXPRODTHREE.INP","r",stdin);
    freopen("MAXPRODTHREE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,dem = 0,x;
    cin >> n >> m;
    vector<abc> so(m);
    for (int i = 0;i < n;i++) {
        cin >> x;
        int bcd = abs(x) % m;
        if (x > 0) {
            so[bcd].duong.push_back(x);
            sort(so[bcd].duong.rbegin(),so[bcd].duong.rend());
            if (so[bcd].duong.size() > 3) so[bcd].duong.pop_back();
        }
        if (x < 0) {
            so[bcd].am.push_back(x);
            sort(so[bcd].am.begin(),so[bcd].am.end());
            if (so[bcd].am.size() > 3) so[bcd].am.pop_back();
        }
    } 
    ll kq = LLONG_MIN;
    for (int i = 0;i < m;i++) {
        for (int j = i;j < m;j++) {
            for (int z = j;z < m;z++) {
                if ((i * j * z) % m == 0) {
                    set<int> xyz = {i,j,z};
                    vector<int> zyx;
                    for (auto it : xyz) {
                        for (auto duong : so[it].duong) {
                            zyx.push_back(duong);
                        }
                        for (auto am : so[it].am) {
                            zyx.push_back(am);
                        }
                    }
                    sort(zyx.begin(),zyx.end());
                    if (zyx.size() < 3) continue;
                    kq = max({kq,(ll)zyx[0] * zyx[1] * zyx[zyx.size() - 1],(ll)zyx[zyx.size() - 1] * zyx[zyx.size() - 2] * zyx[zyx.size() - 3]});
                }
            }
        }
    }
    if (kq == LLONG_MIN) cout << -1;
    else cout << kq;
}