#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;

#define endl '\n'
const lli MOD=1e9+7;
lli binexp(lli b, lli p){
    if(p==0) return 1;
    if(p==1) return b%MOD;
    lli x=binexp(b,p/2);
    x*=x;
    x%=MOD;
    if(p%2==1){
        x*=b;
        x%=MOD;
    }
    return x;
}

void solve(){
    lli n,l;
    cin>>n>>l;
    if(n==1){
        cout<<l<<endl;
        return;
    }
    lli SUM=0;
    vector<lli> values (n);
    for(lli i=0; i<n; ++i){
        cin>>values[i];
        values[i]--;
        SUM+=2*values[i]+1;
    }
    vector<lli> fact (2*l+5,1);
    vector<lli> inv (2*l+5,1);
    for(lli i=2; i<fact.size(); ++i){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
        inv[i]=binexp(fact[i], MOD-2);
    }
    lli ans=0;
    for(lli i=0; i<n; ++i){
        for(lli j=0; j<n; ++j){
            if(i==j) continue;
            for(lli x=0; x<=values[i]+values[j]; ++x){
                if(l-(SUM-values[i]-values[j])-x <0) break;
                lli mult;
                if(x<=min(values[i], values[j])){
                    mult=x+1;
                }
                else if(x<=max(values[i], values[j])){
                    mult=min(values[i], values[j]);
                }
                else{
                    mult=values[i]+values[j]-x+1;
                }
                lli val=fact[l-(SUM-values[i]-values[j])-x+n-2];
                val*=inv[l-(SUM-values[i]-values[j])-x];
                val%=MOD;
                val*=mult;
                val%=MOD;
                ans+=val;
                ans%=MOD;
            }
        }
    }
    cout<<ans<<endl;


}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
 //   cin>>t;
    while(t--){
        solve();
    }
}