#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;


void solve(){
    lli n;
    cin>>n;
    double mn=100000.0;
    for(lli i=0; i<n; ++i){
        double x;
        cin>>x;
        mn=min(mn, x);
    }
    double T;
    cin>>T;
    lli ans=T/mn;
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