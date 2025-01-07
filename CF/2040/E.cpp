    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;
    lli MOD=998244353;
    lli binexp(lli b, lli p){
        if(p==0) return 1ll;
        if(p==1) return b%MOD;
        lli x=binexp(b, p/2);
        x*=x;
        x%=MOD;
        if(p%2) x*=b;
        x%=MOD;
        return x;
    }

    lli inv(lli a){
        return binexp(a, MOD-2);
    }

    
    void dfs(lli x, lli p, vector<vector<lli>> &modu,vector<vector<lli>> &ady,vector<vector<ld>> &real, vector<lli> &parent){
        lli n=modu.size();
        parent[x]=p;
        if(x==0){
            for(lli i=0; i<modu[0].size(); ++i){
                modu[0][i]=0;
                real[0][i]=0;
            }
            for(lli y: ady[x]){
                dfs(y,x,modu,ady,real, parent);
            }
            return;
        }
        if(p==0){
            for(lli i=0; i<modu[0].size(); ++i){
                modu[x][i]=1;
                real[x][i]=1;
       
            }
            for(lli y: ady[x]){
                dfs(y,x,modu,ady,real, parent);
            }
            return;
        }
        if(parent[p]==0){
            for(lli i=1; i<modu[0].size(); ++i){
                modu[x][i]=2;
                real[x][i]=2;
            }
              lli xd=ady[p].size();
            modu[x][0]=(2*xd)%MOD;
            real[x][0]=2*xd;
              for(lli y: ady[x]){
                dfs(y,x,modu,ady, real,parent);
            }
            return;
        }
         lli xd=ady[p].size();
        modu[x][0]=(2*xd+modu[parent[p]][0])%MOD;
        real[x][0]=2*xd+real[parent[p]][0];
        ld mini=real[x][0];
        for(lli i=1; i<modu[0].size(); ++i){
            lli xd2=ady[parent[p]].size();
            ld val=2*xd2+real[parent[parent[p]]][i-1];
            if(val<mini){
                modu[x][i]=(2*xd2+modu[parent[parent[p]]][i-1])%MOD;
                real[x][i]=val;   
            }
            else{
                modu[x][i]=modu[x][i-1];
                real[x][i]=mini;
            }
        }
          for(lli y: ady[x]){
                dfs(y,x,modu,ady,real, parent);
            }
            return;
    }

    void solve(){
        lli n,q;
        cin>>n>>q;
        vector<vector<lli>> ady (n);
        for(lli i=0; i<n-1; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            ady[u].pb(v);
            ady[v].pb(u);
        }
        vector<vector<lli>> modu (n, vector<lli> (n+1));
        vector<vector<ld>> real (n, vector<ld> (n+1));
        vector<lli> parent (n);
        dfs(0, -1, modu, ady, real, parent);
        while(q--){
            lli u, p;
            cin>>u>>p; 
            u--;
            cout<<modu[u][p]<<endl;
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