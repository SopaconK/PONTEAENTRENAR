#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

void solve(){
    lli n,x;
    cin>>n>>x;
    vector<lli> v (x+1, 0);
    vector<lli> h (n);
    vector<lli> p(n);
    for(lli i=0; i<n; ++i){
        cin>>h[i];
    }
    for(lli i=0; i<n; ++i){
        cin>>p[i];
    }
    for(lli i=0; i<n; ++i){
        for(lli j=x; j-h[i]>=0; --j){
            v[j]=max(v[j-h[i]]+p[i], v[j]);
        }
    }
    lli ans=0;
    for(lli y: v){
        ans=max(ans, y);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while (t--){
        solve();
    }
}