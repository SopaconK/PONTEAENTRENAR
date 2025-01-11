    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    

    void solve(){
        lli n,m,q;
        cin>>n>>m>>q;
        vector<vector<pair<lli,lli>>> ady (n);
        vector<pair<lli,pair<lli,lli>>> pesos;
        for(lli i=0; i<m; ++i){
            lli u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            ady[u].pb({v,w});
            ady[v].pb({u,w});
            pesos.pb({w,{u,v}});
        }
        pesos.pb({-1,{-1,-1}});
        sort(pesos.begin(), pesos.end());
        
        vector<vector<vector<lli>>> sol (n, vector<vector<lli>> (n, vector<lli> (m+1)));
        ///BFS inicial 
        for(lli a=0; a<n; ++a){
            queue<pair<lli,lli>>q;
            vector<bool> vis (n, 0);
            q.push({a,0});
            vis[a]=true;
            sol[a][a][0]=0;
            while(!q.empty()){
                lli x=q.front().first;
                lli d=q.front().second;
                q.pop();
                for(auto si: ady[x]){
                    if(vis[si.first]) continue;
                    vis[si.first]=true;
                    sol[a][si.first][0]=d+1;
                    q.push({si.first, d+1});
                }
            }
        }
     
        for(lli i=1; i<=m; ++i){
            for(lli a=0; a<n; ++a){
                for(lli b=0; b<n; ++b){
                    sol[a][b][i]=min(sol[a][b][i-1], min(sol[a][pesos[i].second.first][i-1]+sol[b][pesos[i].second.second][i-1],sol[b][pesos[i].second.first][i-1]+sol[a][pesos[i].second.second][i-1] ));
                 
                }
            }
        }


        while(q--){
            lli a,b,k;
            cin>>a>>b>>k;
            a--;
            b--;
            lli l=1;
            lli r=pesos.size()-1;
            while(r-l>1){
                lli m=(l+r)/2;
//                deb(m);
  //              deb(pesos[m].first);
    //            deb(sol[a][b][m]);
                if(sol[a][b][m]<k){
      //              deb("si");
                    r=m;
                }
                else{
        //            deb("No");
                    l=m+1;
                }
            }
         
      //      deb(l);
        //    deb(pesos[l].first);
          //  deb(sol[a][b][l]);
            if(sol[a][b][l]<k) r=l;
            cout<<pesos[r].first<<" ";
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