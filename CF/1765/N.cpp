    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    string s;
    struct segtree{
        lli l,r;
        lli mini;
        lli pos;
        segtree *left, *right;
        segtree(lli a, lli b): l(a), r(b){
            if(l==r){
                mini=s[l]-'0';
                pos=l;
                left=NULL;
                right=NULL;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l, m);
                right=new segtree(m+1, r);
                if(left->mini <=right->mini){
                    mini=left->mini;
                    pos=left->pos;
                }
                else{
                    mini=right->mini;
                    pos=right->pos;
                }
            }
        }

        pair<lli,lli> query(lli a, lli b){
            if(a<=l && r<=b) return {mini, pos};
            if(b<l || r<a) return {100, a};
            pair<lli,lli> p1=left->query(a,b);
            pair<lli,lli> p2=right->query(a,b);
            if(p1.first<=p2.first){
                return p1;
            }
            return p2;
        }
    };

    struct segtree2{
        lli l,r;
        lli mini;
        lli pos;
        segtree2 *left, *right;
        segtree2(lli a, lli b): l(a), r(b){
            if(l==r){
                mini=s[l]-'0';
                if(mini==0) mini=10;
                pos=l;
                left=NULL;
                right=NULL;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree2(l, m);
                right=new segtree2(m+1, r);
                if(left->mini <=right->mini){
                    mini=left->mini;
                    pos=left->pos;
                }
                else{
                    mini=right->mini;
                    pos=right->pos;
                }
            }
        }

        pair<lli,lli> query(lli a, lli b){
            if(a<=l && r<=b) return {mini, pos};
            if(b<l || r<a) return {100, a};
            pair<lli,lli> p1=left->query(a,b);
            pair<lli,lli> p2=right->query(a,b);
            if(p1.first<=p2.first){
                return p1;
            }
            return p2;
        }
    };

    void solve(){
        cin>>s;
        lli n=s.size();
        lli k;
        cin>>k;
        lli p=0;
        if(k==0){
            cout<<s<<endl;
            return;
        }
        segtree *tree=new segtree(0,n-1 );
        segtree2 *tree2=new segtree2(0, n-1);
        string ans="";
        while(k>0){
            if(p+k>n-1) break;
            pair<lli,lli> p1= tree2->query(p, p+k);
       /*     deb(k);
            deb(p);
            deb(p1.first);
            deb(p1.second);*/
            ans+=s[p1.second];
            k-=(p1.second-p);
            p=p1.second+1;
            break;
        }
        while(k>0){
            if(p+k>n-1) break;
            pair<lli,lli> p1= tree->query(p, p+k);
       /*     deb(k);
            deb(p);
            deb(p1.first);
            deb(p1.second);*/
            ans+=s[p1.second];
            k-=(p1.second-p);
            p=p1.second+1;
        }
        if(k==0){
        for(; p<n; ++p){
            ans+=s[p];
        }
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