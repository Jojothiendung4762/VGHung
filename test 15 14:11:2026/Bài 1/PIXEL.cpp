#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("PIXEL.INP","r",stdin);
    freopen("PIXEL.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dem(1e6 + 1,0);
    int x,khac = 0,toida = 0;
    for (int i = 0;i < n;i++) {
        cin >> x;
        dem[x]++;
    }
    for (int i = 0;i <= 1e6;i++) {
        if (dem[i] > 0) khac++;
        toida = max(toida,dem[i]);
    }
    cout << khac << "\n" << toida;
}