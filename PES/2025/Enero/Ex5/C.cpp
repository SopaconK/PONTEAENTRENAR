    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    vector<lli> tin;
    vector<lli> tout;
    vector<lli> alt;
    vector<vector<lli>> padres;
    void dfs(lli x, lli p, lli &cont, vector<vector<lli>> &ady){
        if(p==-1) alt[x]=0;
        else alt[x]=alt[p]+1;
        padres[x][0]=p;
        if(p==-1) padres[x][0]=0;
        tin[x]=cont;
        cont++;
        for(lli i=1; i<20; ++i){
            padres[x][i]=padres[padres[x][i-1]][i-1];
        }
        for(lli y: ady[x]){
            if(y==p) continue;
            dfs(y,x,cont,ady);
        }
        tout[x]=cont;
        cont++;
    }

    bool ancestro (lli u, lli v){
        if(tin[u]<=tin[v] && tout[v]<=tout[u]) return 1;
        return 0;
    }

    lli lca(lli u, lli v){
        if(ancestro(u,v)) return u;
        if(ancestro(v,u)) return v;
        for(lli i=19; i>=0; --i){
            if(!ancestro(padres[u][i],v)){
                u=padres[u][i];
            }
        }
        return padres[u][0];
    }

    void solve(){
        lli n,m,q;
        cin>>n>>m>>q;
        vector<lli> a (m);
        for(lli i=0; i<m; ++i){
            cin>>a[i];
            a[i]--;
        }
        vector<vector<lli>> ady (n);
        for(lli i=0; i<n-1; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            ady[u].pb(v);
            ady[v].pb(u);
        }
        alt.resize(n,0);
        padres.resize(n, vector<lli> (20,0));
        tin.resize(n,0);
        tout.resize(n,0);
        lli cont=0;
        dfs(0,-1,cont,ady);

        vector<lli> ans (m,0);

        while(q--){
            char c;
            cin>>c;
            if(c=='t'){
                lli f,g,c;
                cin>>f>>g>>c;
                f--;
                g--;
                c--;
                for(lli i=f; i<=g; ++i){
                    lli nod=lca(a[i], c);
                    lli val=alt[a[i]]-alt[nod]+alt[c]-alt[nod];
                    ans[i]-=val;
                    a[i]=c;
                }
            }
            else if(c=='e'){
                lli x,d;
                cin>>x>>d;
                x--;
                for(lli i=0; i<m; ++i){
                    if(a[i]==x){
                        ans[i]+=d;
                    }
                }
            }
            else{
                lli v;
                cin>>v;
                v--;
                cout<<ans[v]<<endl;
            }
      /*      deb("a");
            for(lli i=0; i<m; ++i){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            deb("ans");
            for(lli i=0; i<m; ++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;*/
        }




    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }