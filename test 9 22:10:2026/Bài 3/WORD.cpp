#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("WORD.IN","r",stdin);
    freopen("WORD.OUT","w",stdout);
    str s;
    getline(cin,s);
    str word;
    stringstream ss(s);
    vector<str> daviethoa;
    vector<str> doixung;
    auto doixungkhong  = [] (str& a) {
        int l = 0,r = a.size() - 1;
        while (l < r) {
            if (a[l] != a[r]) return false;
            l++;
            r--;
        }
        return true;
    };
    while (ss >> word) {   
        if (doixungkhong(word)) doixung.push_back(word);
        word[0] = (char)toupper(word[0]);
        daviethoa.push_back(word);
    }
    for (auto i : daviethoa) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : doixung) {
        cout << i << " ";
    }
    cout << doixung.size();
    fclose(stdin);
    fclose(stdout);
}