    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void dfs(lli x, lli p,vector<vector<lli>> &ady, vector<lli> &dp1, vector<lli> &dp2, vector<lli> &dp3, vector<lli> &dp4){
       for(lli y: ady[x]){
        if(y==p) continue;
        dfs(y,x,ady,dp1,dp2,dp3,dp4);
       } 
       if(ady[x].size()==1 && p!=-1){
        dp1[x]=0;
        dp2[x]=-1e10;
        dp3[x]=-1e10;
        dp4[x]=-1e10;
        return;
       }
        dp1[x]=ady[x].size()-1;
        
        for(lli y: ady[x]){
            if(y==p) continue;
            dp2[x]=max(dp2[x], dp1[y]+(lli)ady[x].size()-2);
             dp2[x]=max(dp2[x], dp3[y]+(lli)ady[x].size()-2);
        }
        for(lli y: ady[x]){
            if(y==p) continue;
            dp3[x]=max(dp3[x], dp1[y]+1);
            dp3[x]=max(dp3[x], dp3[y]);
        }
        for(lli y: ady[x]){
            if(y==p) continue;
            dp4[x]=max(dp4[x], dp2[y]+1);
            dp4[x]=max(dp4[x], dp4[y]);
        }
        vector<lli> si;
        for(lli y: ady[x]){
            if(y==p) continue;
            si.pb(max(dp2[y],dp4[y]+1));
        }
        sort(si.rbegin(), si.rend());
        if(si.size()>=2){
            dp4[x]=max(dp4[x], si[0]+si[1]-1);
        }
        deb(x);
        deb(dp1[x]);
        deb(dp2[x]);
        deb(dp3[x]);
        deb(dp4[x]);

    }

    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> adj (n);
        vector<lli> dp1 (n,0);
        vector<lli> dp2 (n,0);
        vector<lli> dp3 (n,0);
        vector<lli> dp4 (n,0);
        for(lli i=0; i<n-1; ++i){
            lli a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        adj[0].pb(-1);
        dfs(0, -1, adj, dp1, dp2,dp3,dp4);
        cout<<max(dp2[0],dp4[0])<<endl;
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