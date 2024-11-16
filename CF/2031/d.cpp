    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    struct segtree{
        segtree *left, *right;
        lli val=0;
        lli l, r;
        segtree(lli a, lli b): l(a), r(b){
            if(a!=b){
                lli m=(a+b)/2;
                left=new segtree(a,m);
                right=new segtree(m+1,b);
            }
        }
        lli query(lli a, lli b){
            if(b<a) return 0;
            if(a<=l && r<=b) return val;
            if(b<l || r<a) return 0;
            return max(left->query(a,b),right->query(a,b));
        }

        void update(lli p, lli x){
            if(l==r){
                val=max(val,x);
            }
            else{
                lli m=(l+r)/2;
                if(p<=m) left->update(p,x);
                else right->update(p,x);
                val=max(left->val, right->val);
            }
        }
    };

    void solve(){
        lli n;
        cin>>n;
        vector<lli> v(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        vector<lli> mini(n);
        mini[n-1]=v[n-1];
        for(lli i=n-2; i>=0; --i){
            mini[i]=min(v[i], mini[i+1]);
        }
        vector<lli> maxi(n);
        maxi[0]=v[0];
        for(lli i=1; i<n; ++i){
            maxi[i]=max(v[i], maxi[i-1]);
        }
        segtree tree(0,n);
        vector<lli> ans (n);
        for(lli i=n-1; i>=0; --i){
         //   deb(i);
           // deb(mini[i]);
            //deb(maxi[i]);

            lli x=tree.query(0, maxi[i]-1);
           // deb(x);
            x=max(x, maxi[i]);
            tree.update(mini[i], x);
            ans[i]=x;
        }
        for(lli i=0; i<n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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