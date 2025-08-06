    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
//    #define endl '\n'

    lli extra1=-1;
    lli extra2=-1;

    void dfs(lli x, lli p, vector<vector<lli>> &ady, vector<lli> &parent, vector<lli> &level){
    //    deb(x);
  //      deb(p);
//        deb(level[x]);
        if(p==-1){
            level[x]=0;
            parent[x]=-1;
        }
        else{
            if(level[x]!=-1){
                extra1=x;
                extra2=p;
                return;
            }
            else{
                level[x]=level[p]+1;
         //       sons[p].pb(x);
                parent[x]=p;
            }
        }
        for(lli y: ady[x]){
            if(y==p) continue;
   //         sons.pb(y);
            dfs(y,x,ady,parent,level);
        }
    }

    lli lca(lli a, lli b, vector<lli> &level, vector<lli> &parent){
       // deb(a);
     //   deb(b);
   //     deb(level[a]);
 //       deb(level[b]);
        while(level[a]>level[b]){
            a=parent[a];
        }
  //      deb(a);
  //      deb(b);
        while(level[b]>level[a]){
            b=parent[b];
        }
      //  deb(a);
    //    deb(b);
        while(a!=b){
            a=parent[a];
            b=parent[b];
        }
  //      deb(a);
//        deb(b);
        return a;
    }


    void solve(){
        lli n,a,b;
        cin>>n>>a>>b;
        a--;
        b--;
   //     deb(n);
       
        extra1=-1;
        extra2=-1;
        vector<vector<lli>> ady (n);
        for(lli i=0; i<n; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            ady[u].pb(v);
            ady[v].pb(u);
        }    
         if(a==b){
            cout<<"NO"<<endl;
            return;
        }
  //      vector<vector<lli>> sons (n);
        vector<lli> parent (n);
        vector<lli> level (n,-1);
   //     deb(n);
        dfs(a,-1, ady, parent,level);
   //     deb(extra1);
     //   deb(extra2);
        lli x=lca(extra1, b,level,parent);
        lli y=lca(extra2,b,level,parent);
    //    deb(x);
  //      deb(y);
        lli lev=max(level[x], level[y]);
        
        if(lev>=level[b]){
            cout<<"YES"<<endl;
            return;
        }
        lli z=lca(extra1,extra2,level,parent);

        if(level[b]-level[x] < min(level[x], level[extra1]-level[x]+level[extra2]+1) ){
            cout<<"YES"<<endl;
            return;
        }
         if(level[b]-level[y] < min(level[y], level[extra1]-level[y]+level[extra2]+1) ){
            cout<<"YES"<<endl;
            return;
        }

        lli w=lca(b,z,level,parent);
        if(level[b]-level[w] < min(level[w], level[extra1]-level[w]+level[extra2]+1)){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
   //         deb(t);
        }
    }