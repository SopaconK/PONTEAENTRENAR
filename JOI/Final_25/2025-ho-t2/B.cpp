#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'

vector<lli> v;

struct segtree{
    lli l,r;
    segtree *left, *right;
    lli val=0;
    segtree(lli a, lli b): l(a), r(b){
        if(l==r){
            left=right=NULL;
            val=v[l];
        }
        else{
            lli m=(l+r)/2;
            left=new segtree(l, m);
            right=new segtree(m+1,r);
            val=max(left->val, right->val);
        }
    }

    lli query(lli a, lli b){
   //     deb(l);
     //   deb(r);
       // deb(val);
        if(a<=l && r<=b) return val;
        if(r<a || b<l) return -1e18;
        return max(left->query(a,b), right->query(a,b));
    }
};


void solve(){
    lli n;
    cin>>n;
    vector<lli> a (2*n);
    vector<lli> b (2*n);
    for(lli i=0; i<n; ++i){
        cin>>a[i];
    }
    for(lli i=0; i<n; ++i){
        cin>>b[i];
    }
    for(lli i=n; i<2*n; ++i){
        a[i]=a[i-n];
        b[i]=b[i-n];
    }
    for(lli i=1; i<2*n; ++i){
        b[i]+=b[i-1];
    }
    v.resize(2*n,0);
    for(lli i=0; i<2*n-1; ++i){
        v[i]=a[i+1]-b[i];
    }
    segtree *tree=new segtree(0, 2*n-2);

    lli ans=1e18;
    for(lli i=0; i<n; ++i){
        lli val=tree->query(i, n+i-2);
        
        
 //       deb(i);
   //     deb(val);
        if(i!=0){
            val+=b[i-1];
        }
     //   deb(val);
        val=max(val, a[i]);
       // deb(val);
        ans=min(ans, val);
    }
    cout<<ans<<endl;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}