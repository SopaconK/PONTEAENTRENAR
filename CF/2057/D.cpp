    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<vector<lli>> v;

    struct segtree{
        lli l,r;
        segtree *left, *right;
        lli maxi;
        lli mini;
        lli dis;
        segtree(lli a, lli b, lli x): l(a), r(b){
            if(l==r){
                maxi=v[x][l];
                mini=v[x][l];
                dis=0;
                left=NULL;
                right=NULL;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l,m,x);
                right=new segtree(m+1,r,x);
                maxi=max(left->maxi, right->maxi);
                mini=min(left->mini, right->mini);
                dis=max(max(left->dis, right->dis), left->maxi-right->mini);
            }
        }
        

        void update(lli p, lli x){
            if(l==r){
                maxi=x;
                mini=x;
            }
            else{
                lli m=(l+r)/2;
                if(p<=m) left->update(p,x);
                else right->update(p,x);
                 maxi=max(left->maxi, right->maxi);
                mini=min(left->mini, right->mini);
                dis=max(max(left->dis, right->dis), left->maxi-right->mini);
            }
        }
        


    };

    void solve(){
        v.clear();
        lli n,q;
        cin>>n>>q;
        v.resize(3, vector<lli> (n));
        for(lli i=0; i<n; ++i){
            cin>>v[0][i];
            v[1][i]=v[0][i]+i;
            v[2][n-1-i]=v[0][i]+n-i-1;
        }

        segtree *tree1= new segtree(0, n-1, 1);
        segtree *tree2= new segtree(0, n-1, 2);
        lli ans=max(tree1->dis, tree2->dis);
        cout<<ans<<endl;
        while(q--){
            lli p,x;
            cin>>p>>x;
            p--;
            tree1->update(p, x+p);
            tree2->update(n-1-p, x+n-1-p);
            ans=max(tree1->dis, tree2->dis);
            cout<<ans<<endl;
        }
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