#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'
struct segtree{
    lli l,m,r;
    lli sum=0;
    bool b=false;
    segtree *left, *right;
    segtree (lli a, lli b): l(a), r(b){
        m=(l+r)/2;
    }

    void add (lli x){
        if(l==r){
            sum=1;
            return;
        }
       
        if(!b){
            
            left=new segtree(l,m);
            right=new segtree(m+1,r);
            b=true;
        }
        
        if(x<=m){
            left->add(x);
        }
        else{
            right->add(x);
        }
        sum=left->sum+right->sum;
    }

    lli query(lli a, lli b){
        if(sum==0) return 0;
        if(a<=l && r<=b) return sum;
        if(r<a || b<l ) return 0;
         if(!b){
            
            left=new segtree(l,m);
            right=new segtree(m+1,r);
            b=true;
        }
        
        return left->query(a,b)+right->query(a,b);
    }

};


void solve(){
    lli n,q;
    cin>>n>>q;
    segtree *tree=new segtree(0, 1e9+5);
    
    tree->add(1);
    
    for(lli i=2; i<=n; ++i){
        vector<lli> v (i,1);
        lli sum=i;
        lli ind=0;
        while(sum<=1e9){
        
            v.pb(sum);
            tree->add(sum);
            sum+=sum; 
            sum-=v[ind];
            ind++;
        }
    }
    while(q--){
        lli a,b;
        cin>>a>>b;
        cout<<tree->query(a,b)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}