    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void dfs(lli n, lli p,lli d, vector<vector<lli>> &dis, vector<lli> &par , vector<vector<lli>> &ady){
        if(p==-1){
            dis[0].pb(n);
            par[n]=-1;
        }
        for(lli x: ady[n]){
            if(x==p) continue;
            par[x]=n;
            dis[d+1].pb(x);
            dfs(x,n,d+1,dis,par,ady);
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
        vector<vector<lli>> dis (n);
        vector<lli> par(n);
        dfs(0, -1, 0, dis, par, ady);
        lli ans=0;
        vector<lli> s (n,0);
        for(lli i=0; i<n; ++i){
          
            if(par[i]!=-1)s[par[i]]++;
            ans=max(ans, (lli) dis[i].size());
            if(par[i]!=-1) ans=max(ans,s[par[i]]+1 );
        }



        vector<lli> col (n, -1);

        vector<lli> v1;
        vector<lli> v2;
    
        bool b=0;  //0 -> insertar en v1 leer en v2
       
        
        col[0]=0;
        v1.pb(0);
        b=1;
        vector<bool> aux (ans, 0);
        
        for(lli i=1; i<n; ++i){
        //    deb(dis[i].size());
            if(dis[i].size()==0) break;
            queue<lli> q;
            if(b){
                for(lli x: v1){
                    q.push(x);
                    aux[x]=1;
                }
                v2.clear();
                lli ind=0;
                for(lli j=0; j<dis[i].size(); ++j){
                  //  deb(j);
                    if(j+1<v1.size()){
                        col[dis[i][j]]=v1[j+1];
                    }
                    else if(j==dis[i].size()-1){
                        if(col[par[dis[i][j]]]!=v1[0]) col[dis[i][j]]=v1[0];
                        else{
                            while(aux[ind]!=0){
                            ind++;
                            ind%=ans;
                            }
                            col[dis[i][j]]=ind;
                            q.push(ind);
                            aux[ind]=1;
                        }
                    }
                    else{
                        while(aux[ind]!=0){
                            ind++;
                            ind%=ans;
                        }
                    //    deb(ind);
                      //  deb(dis[i][j]);
                        col[dis[i][j]]=ind;
                        q.push(ind);
                        aux[ind]=1;
                    }

                    if(s[dis[i][j]]>0){
                        v2.pb(col[dis[i][j]]);
                    }
                }
                while(!q.empty()){
                    aux[q.front()]=0;
                    q.pop();
                }
            }
            else{
                for(lli x: v2){
                    q.push(x);
                    aux[x]=1;
                }
                v1.clear();
                lli ind=0;
                for(lli j=0; j<dis[i].size(); ++j){
                    if(j+1<v2.size()){
                        col[dis[i][j]]=v2[j+1];
                    }
                    else if(j==dis[i].size()-1){
                        if(col[par[dis[i][j]]]!=v2[0]) col[dis[i][j]]=v2[0];
                        else{
                            while(aux[ind]!=0){
                            ind++;
                            ind%=ans;
                            }
                            col[dis[i][j]]=ind;
                            q.push(ind);
                            aux[ind]=1;
                        }
                    }
                    else{
                        while(aux[ind]!=0){
                            ind++;
                            ind%=ans;
                        }
                        col[dis[i][j]]=ind;
                        q.push(ind);
                        aux[ind]=1;
                    }

                    if(s[dis[i][j]]>0){
                        v1.pb(col[dis[i][j]]);
                    }
                }
                while(!q.empty()){
                    aux[q.front()]=0;
                    q.pop();
                }
            }
            b=!b;
        }
     
       vector<vector<lli>> solv (ans);
       for(lli i=0; i<n; ++i){
        solv[col[i]].pb(i);
       }
       cout<<ans<<endl;
       for(lli i=0; i<ans; ++i){
            cout<<solv[i].size()<<" ";
            for(lli x: solv[i]){
                cout<<x+1<<" ";
            }
            cout<<endl;
       }



    //    cout<<ans<<endl;

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