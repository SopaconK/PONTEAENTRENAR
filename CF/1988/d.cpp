    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    vector<vector<lli>> sons;

    void dfs(lli x, lli p, vector<lli> &dp1, vector<lli> &dp2, vector<vector<lli>> &adj, vector<lli> &v){
      dp1[x]+=v[x];
      for(lli y: adj[x]){
        if(y==p) continue;
        sons[x].pb(y);
        dfs(y,x,dp1,dp2,adj,v);
        dp1[x]+=dp2[y];
        dp2[x]+=max(dp1[y], dp2[y]);
      }
    }

    void borrar(lli x, bool b, vector<lli> &v, vector<lli>&dp1, vector<lli> &dp2){ //0 es q si se comieron al de arriba 1 es q no
      if(dp1[x]==0 && dp2[x]==0) return;
 //     deb(dp1[x]);
   //   deb(dp2[x]);
     // deb(b);
     // deb(x);
      if(b){
        if(dp1[x]>=dp2[x]){
          v[x]=0;
       //   deb(v[x]);
          for(lli y: sons[x]){
         //   deb(y);
            borrar(y, 0, v, dp1, dp2);
          }
        }
        else{
          for(lli y: sons[x]){
            borrar(y, 1, v, dp1, dp2);
          }
        }
      }
      else{
        for(lli y: sons[x]){
          borrar(y, 1, v, dp1, dp2);
        }
      }
  //    deb(x);
    //  deb(v[x]);
      //deb(x);
     // deb(dp1[x]);
      dp1[x]=v[x];
      dp2[x]=0;
     // deb(dp1[x]);
      //deb(dp2[x]);
      for(lli y:sons[x]){
        dp1[x]+=dp2[y];
        dp2[x]+=max(dp1[y], dp2[y]);
      }
    }
    void solve(){
      lli n;
      cin>>n;
      sons.clear();
      sons.resize(n+1);
      vector<lli> v (n+1);
      lli sum=0;
      for(lli i=1; i<=n; ++i){
        cin>>v[i];
        sum+=v[i];
      }
      vector<vector<lli>> adj (n+1);
      for(lli i=0; i<n-1; ++i){
        lli a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
      }
      vector<lli> dp1 (n+1,0);
      vector<lli> dp2 (n+1,0);
      dfs(1,0, dp1,dp2,adj, v);
      lli ans=0;
      while(sum>0){
  //      deb(sum);
      ans+=sum;
      sum-=max(dp1[1],dp2[1] );
      borrar(1,1,v,dp1,dp2);

        }
      cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }