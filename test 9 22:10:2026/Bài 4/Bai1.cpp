#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    int n,x;
    cin >> n;
    map<int,int> so;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        so[x]++;
    }
    int toida = 0;
    for (auto i : so) {
        toida = max(toida,i.second);
    }
    cout << toida;
    fclose(stdin);
    fclose(stdout);
}