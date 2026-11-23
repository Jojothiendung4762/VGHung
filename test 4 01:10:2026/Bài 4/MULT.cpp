#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MULT.INP", "r", stdin);
    freopen("MULT.OUT", "w", stdout);
    super int k,n,x;
    cin >> k;
    while (k--) {
        cin >> n >> x;
        cout << x / n << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}