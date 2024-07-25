#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'


void solve(){
    lli n,k,q;
    cin>>n>>k>>q;
    vector<lli> v (200005, 0);
    for(lli i=0; i<n; ++i){
        lli a,b;
        cin>>a>>b;
        v[a]++;
        v[b+1]--;
    }
    for(lli i=1; i<v.size(); ++i){
        v[i]+=v[i-1];
    }
    for(lli i=0; i<v.size(); ++i){
        if(v[i]>=k){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
    }
    for(lli i=1; i<v.size(); ++i){
        v[i]+=v[i-1];
    }
    while(q--){
        lli a,b;
        cin>>a>>b;
        lli ans=v[b]-v[a-1];
        cout<<ans<<endl;
    }


}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
 //   cin>>t;
    while(t--){
        solve();
    }
}