#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define endl '\n'



void solve(){
    lli n,m;
    cin>>n>>m;
    vector<lli> v (n);
    for(lli i=0; i<n; ++i){
        cin>>v[i];
    }
    while(m--){
        lli l,r;
        cin>>l>>r;
        l--;
        r--;
        vector<pair<lli,lli>> sv;
        for(lli i=l; i<=r; ++i){
            sv.pb({v[i], i});
        }
        sort(sv.begin(), sv.end());
        lli ans=0;
        lli ant=sv[0].second;
        for(lli i=1; i<sv.size(); ++i){
            ans+=abs(sv[i].second-ant);
            ant=sv[i].second;
        }
        cout<<ans<<endl;
    }

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