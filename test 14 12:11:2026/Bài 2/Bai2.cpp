#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("Bai2.INP","r",stdin);
    freopen("Bai2.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    cin >> l >> r;
    vector<bool> so(r + 1,false);
    for (int i = 1;i * (i + 1) / 2 <= r;i++) {
        int x = i * (i + 1) / 2;
        for (int j = i; ;j++) {
            int y = j * (j + 1) / 2;
            if (x + y > r) break; 
            so[x + y] = true;
        }
    }
    int dem = 0;
    for (int i = l;i <= r;i++) {
        if(so[i]) dem++;
    }
    cout << dem;
}