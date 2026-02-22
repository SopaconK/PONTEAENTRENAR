    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void dfs(lli n, lli p, vector<lli> &dis, vector<lli> &par , vector<vector<lli>> &ady){
        if(p==-1){
            dis[n]=0;
            par[n]=-1;
        }
        for(lli x: ady[n]){
            if(x==p) continue;
            par[x]=n;
            dis[x]=dis[n]+1;
            dfs(x,n,dis,par,ady);
        }
    }

    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> ady (n);
        for(lli i=0; i<n-1; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            ady[u].pb(v);
            ady[v].pb(u);
        }
        vector<lli> dis (n);
        vector<lli> par(n);
        dfs(0, -1, dis, par, ady);
        lli ans=0;
        vector<lli> s (n,0);
        vector<lli> nd (n, 0);
        for(lli i=0; i<n; ++i){
            nd[dis[i]]++;
            if(par[i]!=-1)s[par[i]]++;
            ans=max(ans, nd[dis[i]]);
            if(par[i]!=-1) ans=max(ans,s[par[i]]+1 );
        //     deb(i);
        //     deb(ans);
        //     deb(par[i]);
        //     deb(dis[i]);
        //    if(par[i]!=-1) deb(s[par[i]]);
        //     deb(nd[dis[i]]);
        }
        cout<<ans<<endl;

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }