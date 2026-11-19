#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mergecount(vector<int>& a,int l,int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    ll nghichthe = 0;
    nghichthe += mergecount(a,l,mid);
    nghichthe += mergecount(a,mid + 1,r);
    vector<int> tam;
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tam.push_back(a[i++]);
        }
        else {
            tam.push_back(a[j++]);
            nghichthe += (mid - i + 1);
        }
    }
    while (i <= mid) tam.push_back(a[i++]);
    while (j <= r) tam.push_back(a[j++]);
    for (int k = 0; k < tam.size(); k++) {
        a[l + k] = tam[k];
    }
    return nghichthe;
}

int main() {
    freopen("NOIDIEM.INP","r",stdin);
    freopen("NOIDIEM.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> so(n);
    for (auto &i : so) {
        cin >> i.first >> i.second;
    }
    sort(so.begin(),so.end());
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        v[i] = so[i].second; 
    }
    cout << mergecount(v,0,n - 1);
}