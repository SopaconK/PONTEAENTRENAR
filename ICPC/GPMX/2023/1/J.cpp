#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'
const lli MOD=1e9+7;

void solve(){
    lli n,q;
    cin>>n>>q;
    vector<lli> v (n+1);
    for(lli i=1; i<=n; ++i){
        cin>>v[i];
    }
    vector<lli> s (n+1,0);
    for(lli i=1; i<=n; ++i){
        s[i]=s[i-1]+v[i];
        s[i]%=MOD;
    }
    vector<lli> m (n+1,0);
    for(lli i=1; i<=n; ++i){
       
        m[i]=v[i]*s[i-1];
        //deb(m[i]);
        m[i]%=MOD;
        //deb(m[i]);
        m[i]+=m[i-1];
       // deb(m[i]);
        m[i]%=MOD;
        //deb(m[i]);
    }
    while(q--){
        //deb("hi");
        lli l,r;
        cin>>l>>r;
        lli ans=m[r]-m[l-1];
        ans-=(s[r]-s[l-1])*s[l-1];
        ans%=MOD;
        while(ans<0){ ans+=MOD;}
        ans%=MOD;
        cout<<ans<<endl;
    }

    

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}