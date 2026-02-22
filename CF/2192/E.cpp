    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    
    vector<vector<pair<lli,lli>>> adj;
    vector<lli> dg;
    vector<lli> ind;

    void dfs(lli x, vector<lli> &used){
      //  deb(x);
        while(ind[x]<adj[x].size()){
            if(used[abs(adj[x][ind[x]].second)]!=0){
                ind[x]++;
                continue;
            }
          //  deb(adj[x][ind[x]].first);
            if(adj[x][ind[x]].second>0){
                used[adj[x][ind[x]].second]=1;
            }
            else{
                 used[-adj[x][ind[x]].second]=-1;
            }
            dg[x]--;
            dg[adj[x][ind[x]].first]--;
            ind[x]++;
            dfs(adj[x][ind[x]-1].first, used);
            
        }
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> a (n);
        vector<lli> b (n);
        vector<lli> used (n+1,0);
        adj.clear();
        adj.resize(n);
        dg.clear();
        dg.resize(n);
        ind.clear();
        ind.resize(n,0);
        
   
        for(lli i=0; i<n; ++i){
            cin>>a[i];
            a[i]--;
            dg[a[i]]++;
        }
        for(lli i=0; i<n; ++i){
            cin>>b[i];
            b[i]--;
            dg[b[i]]++;
        }
        for(lli i=0; i<n; ++i){
            if(a[i]==b[i]){
                dg[a[i]]-=2;
                continue;
            }
            adj[a[i]].pb({b[i], i+1});
            adj[b[i]].pb({a[i], -(i+1)});
        }
        for(lli i=0; i<n; ++i){
            if(dg[i]%2!=0){
                cout<<-1<<endl;
                return;
            }
        }
        for(lli i=0; i<n; ++i){
           while(dg[i])
            dfs(i,used);
        }
        lli ans=0;
        for(lli i=1; i<=n; ++i){
            if(used[i]==-1){
                ans++;
            }
        }
        cout<<ans<<endl;
        for(lli i=1; i<=n; ++i){
            if(used[i]==-1){
                cout<<i<<" ";
            }
        }
        cout<<endl;






       

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