    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    struct segtree{
        lli l,r;
        segtree *left, *right;
        lli ml;
        segtree(lli a, lli b): l(a), r(b){
            if(l==r){
                left=NULL;
                right=NULL;
                ml=l;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l, m);
                right=new segtree(m+1, r);
                ml=l;
            }
        }

        lli query(lli x, lli y){
            if(x<=l && r<=y) return ml;
            if(y<l || r<x) return -1;
            lli z=left->query(x,y);
            if(z==-1){
                return right->query(x,y);
            }
            return z;
        }

        void use(lli x){
            if(l==r){
                ml=-1;
                return;
            }
            lli m=(l+r)/2;
            if(x<=m) left->use(x);
            else right->use(x);
            lli z=left->ml;
            if(z==-1) ml=right->ml;
            else ml=z;
        }
    };
    void solve(){
        lli n,m,k;
        cin>>n>>m>>k;
        vector<lli> a(m);
        for(lli i=0; i<m; ++i) cin>>a[i];
        vector<pair<lli,lli>> v(n);
        for(lli i=0; i<n; ++i){
            lli x,y,z;
            cin>>x>>y>>z;
            k-=y;
            z-=y;
            v[i]={z,x};
        }
        sort(a.begin(), a.end());
        sort(v.begin(), v.end());
        segtree *tree=new segtree(0, m-1);
        vector<lli> ind (m+1, -1);
        ind[a[0]]=0;
        
        for(lli i=1; i<m; ++i){
            if(a[i]!=a[i-1]){
      //          deb(a[i]);
                ind[a[i]]=i;
            }
        }
    //    deb("HI");
        for(lli i=m-1; i>=0; --i){
            if(ind[i]==-1){
                ind[i]=ind[i+1];
            }
        }
        //deb("HIII");
        lli ans=0;
        vector<bool> used (n, 0);
        for(lli i=n-1; i>=0; --i){
            if(ind[v[i].second]==-1) continue;
            lli q=tree->query(ind[v[i].second], m-1);
            if(q==-1) continue;
            used[i]=true;
            ans++;
            tree->use(q);
        }

        for(lli i=0; i<n; ++i){
            if(used[i]) continue;
   //         deb(v[i].first);
     //       deb(k);
            if(v[i].first>k) break;
            k-=v[i].first;
            ans++;
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