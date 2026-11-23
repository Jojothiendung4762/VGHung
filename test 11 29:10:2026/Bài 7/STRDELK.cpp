#include <iostream>
#include <string>
#include <sstream>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("STRDELK.INP","r",stdin);
    freopen("STRDELK.OUT","w",stdout);
    int k,so;
    str n;
    cin >> n >> k;
    str kq = "";
    stringstream ss(n);
    while (ss >> so) {
        while (!kq.empty() && so < kq.back() && k > 0) {
            kq.pop_back();
            k--;
        }
        kq.push_back(so); 
    }
    while (k > 0) {
        kq.pop_back(); 
    }
    while (!kq.empty() && kq[0] == 0) {
        kq.erase(0,1);
    }
    cout << kq;
    fclose(stdin);
    fclose(stdout);
}