#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
//#define endl '\n'

//vector<lli> v;

struct segtree {
    lli l,r;
    lli sum=0;
    segtree *left, *right;
    segtree(lli a, lli b): l(a), r(b){
 //       deb(l);
   //     deb(r);
        if(l==r){
            sum=1;
        }
        else{
            lli m=(l+r)/2;
            left=new segtree(l,m);
            right=new segtree (m+1, r);
            sum=left->sum+right->sum;
        }
    }

    lli query(lli val){
  //      deb(val);
    //    deb(l);
      //  deb(r);
        if(l==r){
            sum=0;
            return l;
        }
        if(left->sum >=val){
            sum--;
            return left->query(val);
        }
        else{
            sum--;
            return right->query(val-left->sum);
        }
    }
};

void solve(){
    lli n;
    cin>>n;
  //  v.resize(n);
    //for(lli i=0; i<n; ++i){
      //  v[i]=i+1;
   // }
    segtree tree(0ll, n-1);
    lli sum=2;
    lli cont=0;
    while(cont<n){
        sum%=tree.sum;
        if(sum==0) sum=tree.sum;
        cout<<tree.query(sum)+1<<" ";
        sum++;
        cont++;
    }
    cout<<endl;
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