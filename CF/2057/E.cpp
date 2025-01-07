    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli find(lli x, vector<lli> &parent){
        if(parent[x]==x) return x;
        return parent[x]=x;
    }

    void unir(lli x, lli y, vector<lli> &parent){
        parent[find(x, parent)]=parent[find(y, parent)];
    }

    lli dfs(lli a, lli b, lli k, lli d, lli v, vector<vector<pair<lli,lli>>> &ady){
        if(d<)
    }

    void solve(){
        lli n,m,q;
        cin>>n>>m>>q;
        vector<vector<pair<lli,lli>>> ady (n);
        vector<pair<lli, pair<lli,lli>>> aristas;
        for(lli i=0; i<m; ++i){
            lli u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            ady[u].pb({v,w});
            ady[v].pb({u,w});
            aristas.pb({w,{u,v}});
        }
        sort(aristas.begin(), aristas.end());
        
        while(q--){
            vector<lli> parent (n);
            vector<vector<pair<lli,lli>>> ady2 (n);
            for(lli i=0; i<n; ++i){
                parent[i]=i;
            }
            lli a,b,k;
            cin>>a>>b>>k;
            a--;
            b--;
            for(auto ar: aristas){
                lli u=ar.second.first;
                lli v=ar.second.second;
                ady2[u].pb({v, ar.first});
                ady2[v].pb({u, ar.first});
                unir(u,v,parent);
                if(find(a,parent)==find(b, parent)){

                }
            }
        }

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