#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;

vector<vector<lli>> dp;
vector<vector<lli>> dp1;
vector<vector<lli>> dp2;
vector<lli> pajaro;
vector<vector<lli>> adj;
vector<vector<lli>> sons;
vector<lli> par;
lli v; 
lli ans=0;

void dfs(lli x, lli p){
    deb(x);
    deb(p);
    for(lli y: adj[x]){
        if(y==p) continue;
        dfs(y,x);
        par[y]=x;
        sons[x].pb(y);

    }
}

void echaleganas(lli x){
    
    for(lli y: sons[x]){
        echaleganas(y);
    
    }
    lli sum=0;

    //Le echo pan

    for(lli y: sons[x]){
        sum+=pajaro[y];
        for(lli i=v; i>=0; --i){
            for(lli j=i; j>=0; --j){
                dp1[x][i]=max(dp1[x][i], dp1[x][j]+dp[y][i-j]-pajaro[y]);
            }
        }
        

    }
    if(par[x]>=0) sum+=pajaro[par[x]];
    for(lli i=1; i<=v; ++i){
        dp1[x][i]=dp1[x][i-1];
    }
    for(lli i=1; i<=v; ++i){
        dp1[x][i]+=sum;
    }
    ans=max(ans, dp1[x][v]);

    //No le hecho pan

     for(lli y: sons[x]){
       // sum+=pajaro[y];
        for(lli i=v; i>=0; --i){
            for(lli j=v-1; j>=0; --j){
                dp2[x][i]=max(dp2[x][i], dp2[x][j]+dp[y][i-j]);
            }
        }
    }
    ans=max(ans, dp2[x][v]); 
    for(lli i=0; i<=v; ++i){
        dp1[x][i]=0;
        dp2[x][i]=0;
    }    
     for(lli y: sons[x]){
      //  sum+=pajaro[y];
        for(lli i=v; i>0; --i){
            dp1[x][i]=max(dp1[x][i],dp[y][i-1]-pajaro[y]);
        }
    }

    for(lli i=1; i<=v; ++i){
        dp1[x][i]+=sum;
    }
      for(lli y: sons[x]){
       // sum+=pajaro[y];
        for(lli i=v; i>=0; --i){
                dp2[x][i]=max(dp2[x][i], dp[y][i]);
        }
    }
    deb("_____________________-");
    deb(x);
    for(lli i=0; i<=v; ++i){
    
        dp[x][i]=max(dp1[x][i], dp2[x][i]);
        
        deb(dp1[x][i]);
        deb(dp2[x][i]);
        deb(dp[x][i]);
    }

}

void solve(){
    lli n;
    cin>>n>>v;

    dp1.resize(n, vector<lli> (v+1));
    dp2.resize(n, vector<lli> (v+1));
    dp.resize(n, vector<lli> (v+1));
    pajaro.resize(n);
    for(lli i=0; i<n; ++i){
        cin>>pajaro[i];
    }
    adj.resize(n);
    sons.resize(n);
    par.resize(n);
    for(lli i=0; i<n-1; ++i){
        lli a,b;
        cin>>a>>b;
        a--;b--;
      
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    echaleganas(0);
    ans=max(ans, dp[0][v]);
    cout<<ans<<endl;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}