    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    struct segtree{
        lli l,r;
        lli val;
        segtree *left, *right;
        segtree(lli a, lli b, vector<lli> &v):l(a), r(b){
            if(l==r){
                val=v[l];
                left=NULL;
                right=NULL;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l, m, v);
                right=new segtree(m+1, r, v);
                val=max(left->val, right->val);
            }
        }  

        lli maxi (lli a, lli b){
            if(a<= l && r<=b) return val;
            if(r<a || b<l) return 0ll;
            return max(left->maxi(a,b), right->maxi(a,b));

        }
    };


    lli query(lli a, lli b, vector<lli> &v, vector<lli> &p, segtree *tree){
        if(b<=a) return 0ll;
        
        lli x=tree->maxi(a, b);
        lli ans= min(query(a, p[x]-1, v, p, tree)+(b-p[x]), query(p[x]+1, b, v, p, tree)+(p[x]-a));
    
        return ans;
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        vector<lli> p(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
            v[i]--;
            p[v[i]]=i;
        }
        
        
        segtree *tree =new segtree(0, n-1, v);
        cout<<query(0, n-1, v, p , tree)<<endl;

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