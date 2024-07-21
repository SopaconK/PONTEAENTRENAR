#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'



void solve(){
   lli n;
   string s;
   cin>>n>>s;
   lli a=0;
   lli b=0;
   lli ans=0;
   for(lli i=0; i<n; ++i){
    if(s[i]=='0'){
        ans+=(a+b);
        b+=a;
        a=1;
    }
    else{
        ans+=(a+1);
        swap(a,b);
        b++;
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