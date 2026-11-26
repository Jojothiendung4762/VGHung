#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG=LLONG_MIN/4;
int n,K; vector<ll> C; vector<vector<int>> g; vector<int> order_,par;

// Cach 1: QHD cai tui tren cay O(N*K) (K nho)
ll knapsack(){
    vector<vector<ll>> d0(n+1),d1(n+1); vector<int> sz(n+1,1);
    for(int t=n-1;t>=0;t--){
        int v=order_[t];
        d0[v]={0,NEG}; d1[v]={NEG,C[v]};
        for(int c:g[v]) if(c!=par[v]){
            int m=min(sz[v]+sz[c],K);
            vector<ll> n0(m+1,NEG),n1(m+1,NEG);
            int ma=d0[v].size()-1, mb=d0[c].size()-1;
            for(int a=0;a<=ma;a++){
                ll x0=d0[v][a],x1=d1[v][a];
                if(x0==NEG&&x1==NEG) continue;
                for(int b=0;b<=mb&&a+b<=m;b++){
                    ll y0=d0[c][b],y1=d1[c][b], yb=max(y0,y1);
                    if(x0!=NEG&&yb!=NEG) n0[a+b]=max(n0[a+b],x0+yb);
                    if(x1!=NEG&&y0!=NEG) n1[a+b]=max(n1[a+b],x1+y0);
                }
            }
            d0[v].swap(n0); d1[v].swap(n1); sz[v]+=sz[c];
            vector<ll>().swap(d0[c]); vector<ll>().swap(d1[c]);
        }
    }
    return max(d0[1][K],d1[1][K]);
}

// Cach 2: Aliens trick (WQS binary search) - CHI dung khi cay la duong di,
// vi chi khi do f(k) moi la ham lom (tren cay tong quat f(k) co the khong lom).
vector<pair<ll,int>> f0,f1;
pair<ll,int> solve(ll lam){
    for(int t=n-1;t>=0;t--){
        int v=order_[t];
        f0[v]={0,0}; f1[v]={C[v]-lam,1};
        for(int c:g[v]) if(c!=par[v]){
            auto b=max(f0[c],f1[c]);
            f0[v].first+=b.first; f0[v].second+=b.second;
            f1[v].first+=f0[c].first; f1[v].second+=f0[c].second;
        }
    }
    return max(f0[1],f1[1]); // hoa thi uu tien so luong lon hon
}
ll aliens(){
    f0.assign(n+1,{0,0}); f1.assign(n+1,{0,0});
    // Moi hieu f(k)-f(k-1) (k<=K) nam trong [-(2K-1)*1e9, 1e9], |.| < 1e14
    // => lambda trong [-1.1e14, 1.1e14]. Tren duong di tap doc lap co <= 5e4 dinh
    // nen gia tri DP <= 5e4 * (1e9 + 1.1e14) ~ 5.5e18 < 9.2e18: vua long long.
    ll lo=-110000000000000LL, hi=110000000000000LL; // tim lambda lon nhat co cnt >= K
    while(lo<hi){
        ll mid=lo+(hi-lo+1)/2;
        if(solve(mid).second>=K) lo=mid; else hi=mid-1;
    }
    auto r=solve(lo);
    return r.first+lo*K;
}
int main(int argc,char**argv){
    freopen("OUTPOST.INP","r",stdin); freopen("OUTPOST.OUT","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>K; C.assign(n+1,0); g.assign(n+1,{});
    for(int i=1;i<=n;i++)cin>>C[i];
    for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}
    par.assign(n+1,0); order_.clear(); order_.push_back(1);
    for(size_t i=0;i<order_.size();i++){int v=order_[i];for(int c:g[v]) if(c!=par[v]){par[c]=v;order_.push_back(c);}}
    int maxdeg=0; for(int i=1;i<=n;i++) maxdeg=max(maxdeg,(int)g[i].size());
    // Cay la duong di (bac <= 2): f(k) lom -> Aliens O(N log). Nguoc lai: cai tui O(N*K).
    int mode = argc>1 ? atoi(argv[1]) : (maxdeg<=2 ? 2 : 1);
    cout<<(mode==1?knapsack():aliens())<<"\n";
}
