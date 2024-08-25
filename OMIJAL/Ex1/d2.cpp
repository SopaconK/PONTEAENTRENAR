#include<bits/stdc++.h>
using namespace std;
using lli=long long int ;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'
struct segtree{
    lli l,r;
    lli sum=0;
    segtree *left, *right;
    segtree(lli a, lli b): l(a), r(b){
        if(l==r) return;
        lli m=(l+r)/2;
        left=new segtree(l, m);
        right=new segtree(m+1,r);
    }

    void add(lli x){
        if(l==r){
            sum++;
            return;
        }
        lli m=(l+r)/2;
        if(x<=m) left->add(x);
        else right->add (x);
        sum++;
    }
    lli query(lli x){
        if(r <= x) return 0;
        if(l>x) return sum;

        return left->query(x)+right->query(x);
    }
};

void solve(){
    lli n;
    cin>>n;
    vector<lli> v (n);
    for(lli i=0; i<n; ++i){
        cin>>v[i];
    }
    long long  inv=0;
    segtree tree (0,n+1);
    for(lli i=0; i<n; ++i){
        inv+=tree.query(v[i]);
        tree.add(v[i]);
    }
   long long  inv2=(n*(n-1))/2;  
    cout<<inv2<<endl<<inv2-inv<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}