#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'


void solve(){
    lli n,q;
    cin>>n>>q;
    vector<lli> v (n);
    for(lli i=0; i<n; ++i){
        cin>>v[i];
    }
    sort(v.rbegin(), v.rend());
    while(q--){
        priority_queue<lli> pq;
        for(lli i=0; i<min(n, 32ll); ++i){
            pq.push(v[i]);
     //       deb(v[i]);
        }
        lli x;
        cin>>x;
        lli ans=0;
        for(lli i=29; i>=0; --i){
            lli aux=x/(1<<i);
            aux%=2;
       //     deb(aux);
            if(aux){
                lli tp=pq.top();
                pq.pop();
                if(tp>=(1<<i)){
                    tp-=(1<<i);
                    pq.push(tp);
                }
                else{
                    ans+=(1<<i)-tp;
                    pq.push(0);
                }
                x-=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}