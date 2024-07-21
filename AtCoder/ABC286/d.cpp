#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'



void solve(){
    lli n,x;
    cin>>n>>x;
    vector<bool> dp(x+1, 0);
    dp[0]=1;
    for(lli i=0; i<n; ++i){
        lli a,b;
        cin>>a>>b;
        for(lli j=0; j<b; ++j){
            for(lli y=x; y>=0; --y){
                if(y-a<0) break;
                if(dp[y-a]) dp[y]=true;
            }
        }
    }
    if(dp[x]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
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