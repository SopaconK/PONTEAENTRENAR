#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
//#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    priority_queue<lli> pq;
    lli ans=0;
    lli x;
    cin>>x;
    pq.push(x);
    
    for(lli i=1; i<n; ++i){
        cin>>x;
        
        lli val=pq.top();
        pq.push(x);
        pq.push(x);
        pq.pop();
        if(val>=x){
            ans+=abs(val-x);
        }
       
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