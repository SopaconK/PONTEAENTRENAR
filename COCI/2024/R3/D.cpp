    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<vector<lli>> sons;
    vector<lli> euler;
    map<lli,lli> pos;
    vector<lli> val;
    vector<lli> f;
    vector<lli> sum;
    vector<lli> par;
    vector<lli> height;
    void dfs(lli x, lli h){
        height[x]=h;
        euler.pb(x);
        pos[x]=euler.size()-1;
        sum[x]=val[x];
        for(lli y: sons[x]){
            dfs(y, h+1);
            f[x]+=f[y]+sum[y];
            sum[x]+=sum[y];
        }
  //      deb(x);
    //    deb(f[x]);
      //  deb(sum[x]);
    }

    lli query(lli x, lli y){
        if(par[x]==y){
            return f[y];
        }
        //deb(f[y]);
        lli aux=pos[x];
        lli l=0;
        lli r=sons[y].size()-1;
        while(l<r-1){
            lli m=(l+r)/2;
            if(pos[sons[y][m]]> aux){
                r=m-1;
            }
            else{
                l=m;
            }
        }
         if(pos[sons[y][r]]< aux){
                l=r;
        }
    //    deb(sum[sons[y][l]]);
      //  deb(sum[x]);
        //deb(val[x]);

        lli ans=f[y]+sum[sons[y][l]]-sum[x]+val[x] - val[x]*(height[x]-height[y]);
        return ans;

    }
    void solve(){
        lli n,q;
        cin>>n>>q;
        sons.resize(n);
        par.resize(n);
        f.resize(n,0);
        sum.resize(n, 0);
        val.resize(n);
        height.resize(n);
        par[0]=-1;
        for(lli i=0; i<n; ++i){
            cin>>val[i];
        }
        for(lli i=1; i<n; ++i){
            lli x;
            cin>>x; 
            x--;
            par[i]=x;
            sons[x].pb(i);
        }
        dfs(0,0);

        while(q--){
            lli x,y;
            cin>>x>>y;
            x--;
            y--;
            cout<<query(x,y)<<endl;
        }

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
        
    }