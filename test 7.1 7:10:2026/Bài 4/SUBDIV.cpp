#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SUBDIV.INP","r",stdin);
    freopen("SUBDIV.OUT","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> so(n);
    vector<ll> tongtruoc(n);
    tongtruoc[0] = so[0];
    for (auto i : so) {
        cin >> i;
    }
    for (int i = 1;i < n;i++) {
        tongtruoc[i] = tongtruoc[i - 1] + so[i];
    }
    for ()
    fclose(stdin);
    fclose(stdout);
}