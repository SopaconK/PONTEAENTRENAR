#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;

void solve(lli t){
    lli n;
    cin>>n;
    lli ans=0;
    lli ant;
    cin>>ant;
    for(lli i=1; i<n; ++i){
        lli x; cin>>x;
        ans=max(ans, abs(ant-x));
        ant=x;
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;   
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}