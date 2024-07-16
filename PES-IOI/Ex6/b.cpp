    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    const lli INF=1e18;
    vector<vector<lli>> dp;
    void dfs(lli x, vector<vector<pair<lli,lli>>> &sons){
        for(auto y: sons[x]){
            dfs(y.first, sons);    
        }
        if(sons[x].size()==0){
            dp[x][0]=0;
            return;
        }
        for(lli i=0; i<=300; ++i){
            dp[x][i]=0;
            for(auto y: sons[x]){
                lli aux=INF;
                for(lli j=0; j<=i; ++j){
                    aux=min(aux, abs(y.second-j)+dp[y.first][i-j]);
                }
                dp[x][i]+=aux;
            }
       //     deb(x);
         //   deb(i);
        }
    }
    void solve(){
        lli n,m;
        cin>>n>>m;
        if(n==1){
            vector<lli> v(m);
            for(lli i=0; i<m; ++i){
                lli p, c;
                cin>>p>>c;
                v[i]=c;
            }
            lli ans=INF;
            for(lli i=0; i<m; ++i){
                lli aux=0;
                for(lli j=0; j<m; ++j){
                    aux+=abs(v[i]-v[j]);
                }
                ans=min(ans, aux);
            }
            cout<<ans<<endl;
        }
        else{
            dp.clear();
            dp.resize(n+m+1,vector<lli> (301,INF));
            vector<vector<pair<lli,lli>>> sons (n+m+1);
            for(lli i=2; i<=n+m; ++i){
                lli p, c;
                cin>>p>>c;
                sons[p].pb({i, c});
            }
            dfs(1, sons);
            lli ans=INF;
            for(lli x: dp[1]){
                ans=min(ans, x);
            }
            cout<<ans<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }