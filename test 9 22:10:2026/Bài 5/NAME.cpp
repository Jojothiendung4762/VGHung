#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("NAME.INP","r",stdin);
    freopen("NAME.OUT","w",stdout);
    int n;
    str s;
    cin >> n;
    cin.ignore();
    unordered_set<str> ten;
    vector<str> kq;
    for (int i = 1;i <= n;i++) {
        getline(cin,s);
        if (ten.insert(s).second) kq.push_back(s); 
    }
    cout << ten.size() << "\n";
    for (auto i : kq) {
        cout << i << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}