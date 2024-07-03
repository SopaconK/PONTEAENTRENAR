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
    vector<lli> fact (3*l+5,1);
    vector<lli> inv (3*l+5,1);
    for(lli i=2; i<fact.size(); ++i){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
        inv[i]=binexp(fact[i], MOD-2);
    }
    if(n>10){
    lli r=values[0];
  //  deb(SUM);
   
    if(l-(n-1)*r-n < 0) {
        cout<<0<<endl;
        return;
    }
    lli ans=fact[l-(n-1)*r];
    ans*=inv[l-(n-1)*r-n];
    ans%=MOD;
   
    cout<<ans<<endl;
    }
    else{
         vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            v[i]=i;
        }
        lli ans=0;
        do{
            lli aux=0;
            for(lli i=0; i<n-1; ++i){
                aux+=max(values[v[i]], values[v[i+1]]);
            }
            if(l-aux-n < 0) continue;
            lli val=fact[l-aux];
            val*=inv[l-aux-n];
            val%=MOD;
            val*=inv[n];
            val%=MOD;
            ans+=val;
            ans%=MOD;
            //
        }while(next_permutation(v.begin(), v.end()));
        cout<<ans<<endl;
    }

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