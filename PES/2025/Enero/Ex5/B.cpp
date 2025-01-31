    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> v;

    struct segtree{
        lli l,r;
        segtree *left, *right;
        vector<lli> val;
        lli tot;
        lli cant=0;
        segtree(lli a,lli b): l(a), r(b){
            val.resize(20);
            if(l==r){
                tot=1;
                for(lli i=0; i<20; ++i){
                    val[i]=v[l]%2;
                    v[l]/=2;
                }
                left=NULL;
                right=NULL;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l,m);
                right=new segtree(m+1,r);
               for(lli i=0; i<20; ++i){
                 val[i]=left->val[i]+right->val[i];
               }
                tot=left->tot+right->tot;
            }
        }

        void upd(lli a, lli b, lli x){
            
            if(a<=l && r<=b){
               cant^=x;

               if(cant!=0){
                if(left!=NULL){
                    left->cant^=cant;
                    right->cant^=cant;
                }
                for(lli i=0; i<20; ++i){
                    if(cant%2){
                        val[i]=tot-val[i];
                    }
                    cant/=2;
                }
               }
               return;
            }
            
             if(cant!=0){
                if(left!=NULL){
                    left->cant^=cant;
                    right->cant^=cant;
                }
                for(lli i=0; i<20; ++i){
                    if(cant%2){
                        val[i]=tot-val[i];
                    }
                    cant/=2;
                }
             }
            if(r<a || b<l) return;
            left->upd(a,b,x);
            right->upd(a,b,x);
            for(lli i=0; i<20; ++i){
                 val[i]=left->val[i]+right->val[i];
               }
        }
        
        lli query(lli a, lli b){
              if(cant!=0){
                if(left!=NULL){
                    left->cant^=cant;
                    right->cant^=cant;
                }
        //        deb(l);
          //      deb(r);
            //    deb(cant);
                for(lli i=0; i<20; ++i){
                    if(cant%2){
                        val[i]=tot-val[i];
                    }
                    cant/=2;
                }
              }
            if(a<=l && r<=b){
                lli ans=0;
                lli pow=1;
       //         deb(l);
         //       deb(r);
                for(lli i=0; i<20; ++i){
                    ans+=val[i]*pow;
                    pow*=2;
                }
           //     deb(ans);
                return ans;
            }
            if(r<a || b<l) return 0ll;
            return left->query(a,b)+right->query(a,b);
        }
    };

    void solve(){
        lli n;
        cin>>n;
        v.resize(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        segtree *arb =new segtree(0,n-1);
        

        lli m;
        cin>>m;

        while(m--){
            lli t;
            cin>>t;
            if(t==1){
                lli l,r;
                cin>>l>>r;
                l--;
                r--;
                lli ans=0;
            
                
                ans+=arb->query(l,r);
                cout<<ans<<endl;
            }
            else{
                lli l,r;
                cin>>l>>r;
                l--;
                r--;
                lli x;
                cin>>x;
                
                arb->upd(l,r,x);
                 
            }
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
   //     cin>>t;
        while(t--){
            solve();
        }
    }