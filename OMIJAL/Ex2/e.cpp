#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

lli MOD=1e9+7;
lli binexp(lli b, lli p){
    if(p==0) return 1ll;
    if(p==1) return (b%MOD);
    lli x=binexp(b,p/2);
    x*=x;
    x%=MOD;
    if(p%2){
        x*=b;
        x%=MOD;
    }
    return x;
}


void solve(){
    lli n,m;
    cin>>n>>m;
    lli a=binexp(m,n);
    lli b=1;
    for(lli i=1; i<=m+n-1; ++i){
        b*=i;
        b%=MOD;
    }
    
    for(lli i=1; i<=n; ++i){
        b*=binexp(i, MOD-2);
        b%=MOD;
    }

    for(lli i=1; i<=m-1; ++i){
        b*=binexp(i, MOD-2);
        b%=MOD;
    }
    b*=2;
    b%=MOD;
  
    lli ans=a-b+m;

    ans%=MOD;
    ans+=MOD;
    ans%=MOD;
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