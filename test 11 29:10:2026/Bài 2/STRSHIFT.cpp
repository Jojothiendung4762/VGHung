#include <iostream>
#include <string>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("STRSHIFT.INP","r",stdin);
    freopen("STRSHIFT.OUT","w",stdout);
    str s;
    int k;
    cin >> s >> k;
    int dai = s.size();
    if (k < dai) {
        cout << s.substr(dai - k,k) + s.substr(0,dai - k); 
    } 
    else {
        cout << s;
    }
    cout << "\n";
    int na = 0;
    for (auto i : s) {
        char koin = tolower(i);
        if (koin == 'u' || koin == 'e' || koin == 'o' || koin == 'a' || koin == 'i') {
            na++;
        }
    }
    cout << na;
    fclose(stdin);
    fclose(stdout);
}