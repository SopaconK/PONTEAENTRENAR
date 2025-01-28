    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

        void dfs(lli x, lli p, vector<vector<lli>> &ady, vector<lli> &euler, vector<pair<lli,lli>> &pos){
        pos[x].first=euler.size();
        euler.pb(0);
        for(lli y: ady[x]){
            if(y==p) continue;
            dfs(y,x,ady,euler,pos);
        }
        pos[x].second=euler.size();
        euler.pb(0);
    }

    struct segtree{
        lli l,r;
        segtree *left, *right;
        lli sum=0;
        segtree(lli a, lli b): l(a), r(b){
            if(l==r){
                sum=0;
            }
            else{
                lli m=(l+r)/2;
                left=new segtree(l, m);
                right=new segtree(m+1,r);
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

        lli query(lli a, lli b){
            if(a<=l && r<=b) return sum;
            if(r<a || b<l) return 0;
            return left->query(a,b)+right->query(a,b);
        }
    };

    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> w (n+1);
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            w[x].pb(i);
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
        dfs(0,-1,ady,euler,pos);
        segtree *tree=new segtree(0, euler.size()-1);
        lli cont=0;
        lli p=n;
        while(w[p].size()==0) p--;
        for(lli x: w[p]){
            tree->update(pos[x].first,1);
            cont++;
        }
        p--;
        while(p>=0){
            if(w[p].size()==0){
                p--;
                continue;
            }
            for(lli y: w[p]){
              
                if(tree->query(pos[y].first, pos[y].second)<cont){
                    cout<<y+1<<endl;
                    return;
                }
            }
            for(lli x: w[p]){
            tree->update(pos[x].first,1);
            cont++;
            }
            p--;
        }
        cout<<0<<endl;
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