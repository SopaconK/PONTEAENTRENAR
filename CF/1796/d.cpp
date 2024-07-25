#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'
const lli INF=1e18;

struct segtree{
    lli l,r;
    lli val;
    segtree *left, *right;
    segtree( lli a, lli b, vector<lli> &v): l(a), r(b){
        if(l==r){
            val=v[l];
        }
        else{
            lli m=(l+r)/2;
            left= new segtree(l,m,v);
            right= new segtree(m+1,r,v);
            val=max(left->val, right->val);
        }
    }
    lli ma(lli L,lli R){
        if(L>R) return -INF;
        if(r<L || R<l) return -INF;
        if(L<=l && r<=R) return val;
        return max(left->ma(L,R), right->ma(L,R));
    }
};

void solve(){
    lli n,k,x;
    cin>>n>>k>>x;
    vector<lli> v (n);
    for(lli i=0; i<n; ++i){
        cin>>v[i];
        v[i]-=x;
    }
    for(lli i=1; i<n; ++i){
        v[i]+=v[i-1];
    }
    segtree tree(0,n-1,v);
    x*=2;
    lli ans=0;
    for(lli i=0; i<n; ++i){
     //   deb(i);
        lli pre;
        if(i==0) pre=0;
        else pre=v[i-1];
        //Todos los que no pueden hacer +x k veces
        for(lli j=i; j<min(n, i+k); ++j){
            lli val=v[j]-pre;
            if(j-i+1<=n-k){
                ans=max(ans, val);
            }
            val+=(j-i+1)*x;
            ans=max(ans, val);
            
        }
     //   deb(ans);
        //Todos los que pueden hacer +x k veces
        lli l=i+k-1;
        lli r=n-1;
        
        lli val=tree.ma(l,r);
        val-=pre;
        val+=k*x;
        ans=max(ans, val);
    //    deb(ans);
       //Todos los que pueden no hacer nada (size) veces

        l=i;
        r=i+(n-k-1);
        r=min(r, n-1);
        val=tree.ma(l,r)-pre;
        ans=max(ans, val);
      //  deb(ans);
        //Todos los que no pueden hacer nada (size) veces
        for(lli j=1; j<k; ++j){
            r=i+(n-k-1)+j;
            if(r>=n) break;
            val=v[r]-pre;
            val+=j*x;
            ans=max(ans, val);
        }
        //deb(ans);
    }
    cout<<ans<<endl;
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