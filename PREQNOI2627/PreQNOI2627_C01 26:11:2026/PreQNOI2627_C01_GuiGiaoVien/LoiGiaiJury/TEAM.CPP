#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("TEAM.INP","r",stdin); freopen("TEAM.OUT","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<long long> a(n),d(n);
    for(auto&v:a)cin>>v;
    for(int i=0;i<n;i++){long long b;cin>>b;d[i]=a[i]-b;}
    // A_i+A_j=B_i+B_j  <=>  d_i + d_j = 0, voi d = A - B
    sort(d.begin(),d.end());
    long long ans=0; int l=0,r=n-1;
    while(l<r){
        long long s=d[l]+d[r];
        if(s<0) l++; else if(s>0) r--;
        else if(d[l]==d[r]){ long long k=r-l+1; ans+=k*(k-1)/2; break; } // ca hai = 0
        else{
            long long cl=0,cr=0; long long vl=d[l],vr=d[r];
            while(l<=r&&d[l]==vl){cl++;l++;}
            while(r>=l&&d[r]==vr){cr++;r--;}
            ans+=cl*cr;
        }
    }
    cout<<ans<<"\n";
}
