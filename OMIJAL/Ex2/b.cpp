#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;


void solve(){
    lli n,f;
    cin>>n>>f;
    lli ans=0;
    for(lli i=0; i<n; ++i){
        lli x;
        cin>>x;
        ans+=abs(x-f);
    }
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