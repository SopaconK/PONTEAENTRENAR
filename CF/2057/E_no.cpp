    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'


    void dfs(lli x, lli orig, lli d, vector<bool> &visitados, vector<vector<vector<bool>>> &check, vector<vector<pair<lli,lli>>> &ady){

        visitados[x]=true;
        check[orig][x][d]=true;
        for(auto u:ady[x]){
            lli nod=u.first;
            if(visitados[nod]) continue;
            if(check[orig][nod][d+1]) continue;
            dfs(nod, orig, d+1,visitados,check,ady);
        }
        visitados[x]=false;
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
            deb(u);
            deb(v);
            aristas.pb({w,{u,v}});
        }
        sort(aristas.begin(), aristas.end());
        vector<bool> visitados (n, 0);
        vector<vector<vector<bool>>> check (n, vector<vector<bool>> (n, vector<bool> (m+5,0)));
        for(lli i=0; i<n; ++i){
            dfs(i,i,0,visitados,check,ady);
        }
        while(q--){
            lli a,b,k;
            cin>>a>>b>>k;
            for(auto ar:aristas){
                lli u=ar.second.first;
                lli v=ar.second.second;
                lli ans=-1;
                for(lli i=0; i<=k-1; ++i){
                    deb(a);
                    deb(b);
                    deb(u);
                    deb(v);
                    deb(i);
                    deb(k-1-i);
                    deb(check[a][u][i]);
                    deb(check[b][v][k-1-i]);
                    if(check[a][u][i] && check[b][v][k-1-i]){
                        ans=ar.first;
                        break;
                    }
                    if(check[b][u][i] && check[a][v][k-1-i]){
                        ans=ar.first;
                        break;
                    }
                }
                if(ans!=-1){
                    cout<<ans<<endl;
                    break;
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