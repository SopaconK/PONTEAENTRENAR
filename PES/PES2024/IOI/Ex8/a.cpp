#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;

vector<lli> paj;
vector<vector<lli>> adj;
vector<vector<lli>> sons;
vector<lli> par;

void dfs(lli x, lli p){
    for(lli y: adj[x]){
        if(y==p) continue;
        sons[x].pb(y);
        par[y]=x;
        dfs(y,x);
    }
}

vector<vector<lli>> dp1; // abajo usando migaja
vector<vector<lli>> dp2; //abajo no usando
vector<vector<lli>> dp3; // abajo usando migaja
vector<vector<lli>> dp4; //abajo no usando
lli v;
lli ans;
void echaleganas(lli x){
    lli sum=0;
    for(lli y: sons[x]){
        sum+=paj[y];
        echaleganas(y);
    }
    if(x!=0) sum+=paj[par[x]];
    dp1[x][1]=sum;
    dp3[x][1]=sum;
   // ans=max(ans, sum);
    for(lli y: sons[x]){
         
        for(lli i=1; i<=v; ++i){
            ans=max(ans, dp1[x][i]+dp3[y][v-i]-paj[y]);
            ans=max(ans, dp1[x][i]+dp4[y][v-i]-paj[y]);
            ans=max(ans, dp2[x][i]+dp3[y][v-i]);
            ans=max(ans, dp2[x][i]+dp4[y][v-i]);
            ans=max(ans, dp3[x][i]+dp1[y][v-i]-paj[x]);
            ans=max(ans, dp3[x][i]+dp2[y][v-i]);
            ans=max(ans, dp4[x][i]+dp1[y][v-i]-paj[x]);
            ans=max(ans, dp4[x][i]+dp2[y][v-i]);
        }
     //   deb(x);
       // deb(y);
        //deb(ans);
        for(lli i=1; i<=v; ++i){
            dp1[x][i]=max(dp1[x][i], dp1[y][i-1]+sum-paj[x]);
            dp1[x][i]=max(dp1[x][i], dp2[y][i-1]+sum);

            dp2[x][i]=max(dp2[x][i], dp1[y][i]-paj[x]);
            dp2[x][i]=max(dp2[x][i], dp2[y][i]);

            dp3[x][i]=max(dp3[x][i], dp3[y][i-1]+sum-paj[y]);
            dp3[x][i]=max(dp3[x][i], dp4[y][i-1]+sum-paj[y]);

            dp4[x][i]=max(dp4[x][i], dp3[y][i]);
            dp4[x][i]=max(dp4[x][i], dp4[y][i]);
        }
     /*   for(lli i=0; i<=v; ++i){
            cout<<dp1[x][i]<<" ";
        }
        cout<<endl;
        for(lli i=0; i<=v; ++i){
            cout<<dp2[x][i]<<" ";
        }
        cout<<endl;
        for(lli i=0; i<=v; ++i){
            cout<<dp3[x][i]<<" ";
        }
        cout<<endl;
        for(lli i=0; i<=v; ++i){
            cout<<dp4[x][i]<<" ";
        }
        cout<<endl;*/
    }

}


void solve(){
    lli n;
    cin>>n>>v;
    ans=0;
    paj.resize(n);
    for(lli i=0; i<n; ++i){
        cin>>paj[i];
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
    dp1.resize(n, vector<lli> (v+1,0));
    dp2.resize(n, vector<lli> (v+1,0));
    dp3.resize(n, vector<lli> (v+1,0));
    dp4.resize(n, vector<lli> (v+1,0));
    echaleganas(0);
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