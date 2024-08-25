#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

void solve(){
    lli n,a,b;
    cin>>n>>a>>b;
    vector<lli> v (n+1,0);
    for(lli i=1; i<=n; ++i){
        cin>>v[i];
    }
    for(lli i=1; i<=n; ++i){
        v[i]+=v[i-1];
    }
    lli ans=0;
    lli L=0;
    lli R=0;
    lli c,d;
    for(lli i=0; i<n; ++i){
        c=a+v[i];
        d=b+v[i];
        while(L<=n && v[L]<c) L++;
        while(R<n && v[R+1]<=d) R++;
  
        ans+=(R-L+1);
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}