#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'


struct segtree{
    lli l,r;
    lli sum=0;
    segtree *left, *right;
    segtree(lli a, lli b): l(a), r(b){
        if(l!=r){
            lli m=(l+r)/2;
            left=new segtree(l, m);
            right=new segtree(m+1,r);
        }
    }

    void update(lli L, lli R, lli x){
        if(r<L || R<l) return;
     
        if(L<=l && r<=R){
            sum+=x;
            return;
        }
        left->update(L,R,x);
        right->update(L,R,x);
    }

    lli val (lli x){
   
        if(l==r) return sum;
        left->sum+=sum;
        right->sum+=sum;
        sum=0;
        lli m=(l+r)/2;
        if(x<=m) return left->val(x);
        return right->val(x);
    }
};

void solve(){
    lli n,m,k;
    cin>>n>>m>>k;
    vector<lli> v (n);
    for(lli i=0; i<n; ++i){
        cin>>v[i];
    }
    vector<lli> l (m);
    vector<lli> r (m);
    vector<lli> d (m);
    for(lli i=0; i<m; ++i){
        cin>>l[i]>>r[i]>>d[i];
        l[i]--;
        r[i]--;
    }
    
    vector<lli> aux (m+1,0);
    while(k--){
        lli x,y;
        cin>>x>>y;
        x--;
        y--;
        aux[x]++;
        aux[y+1]--;
    }
    for(lli i=1; i<=m; ++i){
        aux[i]+=aux[i-1];
    }

    segtree tree(0, n);

    for(lli i=0; i<m; ++i){
        tree.update(l[i], r[i], aux[i]*d[i]);
    }
    for(lli i=0; i<n; ++i){
        v[i]+=tree.val(i);
        cout<<v[i]<<" ";
    }
    cout<<endl;

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
}