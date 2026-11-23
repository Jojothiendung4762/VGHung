#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("Tong.inp","r",stdin);
    freopen("Tong.out","w",stdout);
    int n;
    cin >> n;
    cout << n * (n - 1) / 2;
    fclose(stdin);
    fclose(stdout);
}