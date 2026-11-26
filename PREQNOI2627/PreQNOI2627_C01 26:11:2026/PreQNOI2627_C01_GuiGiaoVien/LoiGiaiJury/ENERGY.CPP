#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("ENERGY.INP","r",stdin); freopen("ENERGY.OUT","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,L,R; cin>>n>>L>>R;
    vector<long long> P(n+1,0),dp(n+1,0);
    for(int i=1;i<=n;i++){long long a;cin>>a;P[i]=P[i-1]+a;}
    // dp[i] = max(dp[i-1], max_{i-R<=j<=i-L} (dp[j]-P[j]) + P[i])
    deque<int> dq; // j tang dan, dp[j]-P[j] giam dan
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int j=i-L;
        if(j>=0){
            while(!dq.empty()&&dp[dq.back()]-P[dq.back()]<=dp[j]-P[j]) dq.pop_back();
            dq.push_back(j);
        }
        while(!dq.empty()&&dq.front()<i-R) dq.pop_front();
        if(!dq.empty()) dp[i]=max(dp[i],dp[dq.front()]-P[dq.front()]+P[i]);
    }
    cout<<dp[n]<<"\n";
}
