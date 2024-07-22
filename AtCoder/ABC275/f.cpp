#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

const lli INF=1e10;
const lli cot=1e9;

void solve(){
   lli n,m;
   cin>>n>>m;
   vector<lli> v (n);
   for(lli i=0; i<n; ++i){
    cin>>v[i];
   }
   vector<lli> dp1 (m+1, INF);
   vector<lli> dp2 (m+1, INF);
   dp1[0]=1;
   dp2[0]=1;
   for(lli i=n-1; i>=0; --i){
        for(lli j=m; j>=0; --j){
            if(j-v[i]<0) break;
            dp2[j]=dp2[j-v[i]];
        }
        for(lli j=m; j>=0; --j){
            if(j-v[i]<0){
                dp2[j]=INF;
                continue;
            }
            dp2[j]=min(dp2[j], dp1[j-v[i]]+1);
        }
        if(i==0){
            for(lli j=0; j<=m; ++j){
                dp2[j]--;
            }
        }
       
        for(lli j=0; j<=m; ++j){
            dp1[j]=min(dp1[j], dp2[j]);
         
        }

   }
   for(lli i=1; i<=m; ++i){
    if(dp1[i]>=cot) cout<<-1<<endl;
    else cout<<dp1[i]<<endl;
   }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
   // cin>>t;
    while (t--){
        solve();
    }
}