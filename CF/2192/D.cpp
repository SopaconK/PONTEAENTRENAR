    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> v1;
    vector<lli> v2;
    vector<lli> s;
    vector<lli> d;
    vector<lli> w;
    vector<vector<lli>> adj;

    void dfs(lli x, lli p){
       
        for(lli u: adj[x]){
            if(u==p) continue;
            dfs(u, x);
        }
        lli maxi=0;
        lli maxi2=0;
        for(lli u: adj[x]){
            if(u==p) continue;
            if(d[u]>maxi){
                maxi2=maxi;
                maxi=d[u];
            }
            else{
                if(d[u]>maxi2){
                    maxi2=d[u];
                }
            }
            v1[x]+=v1[u];
            v1[x]+=s[u];
            s[x]+=s[u];
        }
        s[x]+=w[x];
        d[x]=maxi+1;
        v2[x]=v1[x];
        for(lli u: adj[x]){
            if(u==p) continue;
            v2[x]=max(v2[x], v1[x]+v2[u]-v1[u]);
            if(maxi==d[u]){
                v2[x]=max(v2[x], v1[x]+s[u]*maxi2);
            }
            else{
                 v2[x]=max(v2[x], v1[x]+s[u]*maxi);
            }
        }

    }

    void solve(){
        v1.clear();
        v2.clear();
        s.clear();
        d.clear();
        w.clear();
        adj.clear();
        lli n;
        cin>>n;
        v1.resize(n, 0);
        v2.resize(n, 0);
        s.resize(n, 0);
        d.resize(n, 0);
        w.resize(n, 0);
        adj.resize(n);
        for(lli i=0; i<n; ++i){
            cin>>w[i];
        }
        for(lli i=0; i<n-1; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,-1);
        for(lli i=0; i<n; ++i){
            cout<<v2[i]<<" ";
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