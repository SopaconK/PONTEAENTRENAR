#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;


void solve(){
    lli a,b;
    cin>>a>>b;
    lli p;
    lli ans=b;
    lli cons=b;
    for(lli i=2; i*i<=cons; ++i){
        if(b%i==0){
            if(a%i==0){
                ans=a;
            }
            lli c=a/i;
            c++;
            c*=i;
            ans=min(ans, c);
            b/=i;
            i--;
        }
    }
    lli i=b;
    if(i>1){
     if(a%i==0){
                ans=a;
            }
            lli c=a/i;
            c++;
            c*=i;
            ans=min(ans, c);
            b/=i;
            i--;
    }
    cout<<ans<<endl;
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