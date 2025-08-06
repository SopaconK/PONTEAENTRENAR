    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

lli ans;
lli ini;
lli fin;

    void dfs(lli x, lli p,lli w, vector<lli> &lev, vector<lli> &masalto, vector<pair<lli,lli>> &parent, vector<vector<pair<lli,lli>>> &ady, vector<vector<lli>> &sons){
        if(p==-1){
            lev[x]=0;
        }
        else{
            if(lev[x]!=-1){
                if(w<ans){
                    ans=w;
                    ini=p;
                    fin=x;
                }
                masalto[x]=min(masalto[x], lev[p]);
                return;
            }
            else{
                lev[x]=lev[p]+1;
                parent[x]={p, w};
                sons[p].pb(x);
            }
            
        }
        for(auto a: ady[x]){
            if(a.first==p) continue;
            dfs(a.first, x, a.second, lev,masalto,parent,ady,sons);
        }
    }


    void dfs2(lli x, vector<vector<lli>> &sons, vector<lli> &level, vector<pair<lli,lli>> &parent, vector<lli> &masalto, vector<lli> &masbajo){
        if(masalto[x]<level[x]){
            masbajo[x]=x;
        }
        for(lli y: sons[x]){
            dfs2(y, sons, masalto);
            if(masalto[y]<masalto[x]){
                masalto[x]=masalto[y];
                masbajo[x]=masbajo[y];
            }
        }
        if(masalto[x]<level[x]){
            if(ans>parent[x].second){
                ans=parent[x].second;
                ini=masbajo[x];
                
            }
        }
    }

    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<pair<lli,lli>>> ady (n);
        for(lli i=0; i<m; ++i){
            lli u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            ady[u].pb({v,w});
            ady[v].pb({u,w});
        }
        vector<lli> lev (n,-1);
        vector<lli> masalto (n, 1e18);
        vector<lli> parent (n, -1);
        vector<vector<lli>> sons (n);
        lli ans=1e18;
        lli ini=-1;
        lli fin=-1;
        
        for(lli i=0; i<n; ++i){
            if(lev[i]==-1){
                dfs(i, -1, -1, lev, maslato, parent, ady, sons);
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