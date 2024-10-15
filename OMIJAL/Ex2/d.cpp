#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;


void solve(){
    lli n;
    cin>>n;
    map<lli,lli> mp;
    for(lli i=0; i<n; ++i){
        lli x;
        cin>>x;
        mp[x]++;
    }
    bool gana=false;
    for(lli i=1; i<=n; ++i){
        if(mp[i]%2){
            gana=true;
            break;
        }
    }
    if(gana){
        cout<<"SI"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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