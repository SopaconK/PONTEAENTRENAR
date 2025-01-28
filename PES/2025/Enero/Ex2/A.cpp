    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    void dfs(lli x, lli p, vector<vector<lli>> &ady, vector<lli> &euler, vector<pair<lli,lli>> &pos, vector<lli> &v){
        pos[x].first=euler.size();
        euler.pb(v[x]);
        for(lli y: ady[x]){
            if(y==p) continue;
            dfs(y,x,ady,euler,pos,v);
        }
        pos[x].second=euler.size();
        euler.pb(-v[x]);
    }

    struct segtree{
        lli l,r;
        segtree *left, *right;
        lli sum=0;
        segtree(lli a, lli b, vector<lli> &euler): l(a), r(b){
            if(l==r){
                sum=euler[l];
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l, m,euler);
                right=new segtree(m+1,r,euler);
                sum=left->sum+right->sum;
            }
        }

        void update(lli s, lli x){
            if(l==r){
                sum=x;
            }
            else{
                lli m=(l+r)/2;
                if(s<=m){
                    left->update(s,x);
                }
                else{
                    right->update(s,x);
                }
                sum=left->sum+right->sum;
            }
        }

        lli query(lli s){
            if(r<=s) return sum;
            if(l>s) return 0;
            return left->query(s)+right->query(s);
        }
    };

    void solve(){
        lli n,q;
        cin>>n>>q;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        vector<vector<lli>> ady(n);
        for(lli i=0; i<n-1; ++i){
            lli a,b;
            cin>>a>>b;
            a--;
            b--;
            ady[a].pb(b);
            ady[b].pb(a);
        }
        vector<lli> euler;
        vector<pair<lli,lli>> pos(n, {0,0});
        dfs(0,-1,ady,euler,pos,v);
        segtree *tree=new segtree(0, euler.size()-1,euler);
        while(q--){
            lli type;
            cin>>type;
            if(type==1){
                lli s,x;
                cin>>s>>x;
                s--;
                euler[pos[s].first]=x;
                euler[pos[s].second]=x;
                tree->update(pos[s].first,x);
                tree->update(pos[s].second,-x);
            }
            else{
                lli s;
                cin>>s;
                s--;
                cout<<tree->query(pos[s].first)<<endl;
            }
        }
        
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
    }   