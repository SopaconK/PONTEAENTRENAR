#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=int;
#define deb(x) cout<<#x<<": "<<x<<endl;
//#define endl '\n'
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
vector<vector<pair<lli,lli>>> adj;
vector<lli> sz;
vector<bool> is_rem;

lli get_sizes(lli x, lli p){
    sz[x]=1;
    for(auto a: adj[x]){
        lli y=a.first;
        if(y==p || is_rem[y]) continue;
        sz[x]+=get_sizes(y,x);
    }
    return sz[x];
}

lli get_centroid (lli x, lli treesz, lli p){
    for(auto a: adj[x]){
        lli y=a.first;
        if(y==p || is_rem[y]) continue;
        if(sz[y]*2>treesz){
            return get_centroid(y, treesz,x);
        }
    }
    return x;
}

lli L,W;
struct Query{
    lli l,x,s,t;  //longitud peso subtree tipo
};

void dfs(lli x, vector<Query> &v, lli p, lli l, lli w, lli s){
    if(l>L || w>W) return;
    Query aux ={l, w, s, 0};
    v.pb(aux);
    aux= {L-l, W-w, s, 1};
    v.pb(aux);
    for(auto a: adj[x]){
        lli y=a.first;
        if(y==p || is_rem[y]) continue;
        dfs(y,v,x, l+1, w+a.second, s);
    }
}

bool customComparator(Query a, Query b){
    if(a.l<b.l) return true;
    if(a.l > b.l) return false;
    if(a.t && b.t==0) return false;
    if(a.t==0 && b.t==1) return true;
    return a.x<=b.x;
}


long long ans=0;


struct BIT{
    vector<int> b;
    lli n;

  void init(lli _n) {
    n = _n;
    for(lli i = 0 ; i <= n ; ++i) b.pb(0);
  }
  lli lowbit(lli x) { return x & (-x); }
  void update(lli x, lli v) {
    for(lli i = x ; i <= n ; i += lowbit(i)){
        b[i] += v;
    }
  }
  lli query(lli x) {
    lli ans = 0;
    for(lli i = x ; i > 0 ; i -= lowbit(i)) ans += b[i];
    return ans;
  }
} bit;

void resolver(lli l, lli r, vector<Query> &v){
 if(l!=r){
        lli m=(l+r)/2;
        resolver(l,m,v);
        resolver(m+1,r,v);
       vector<lli> his;
       vector<Query> tmp;
        lli x=l;
        lli y=m+1;
        while(x<=m && y<=r){
            if(v[x].x<=v[y].x){
               
                if(v[x].t==0){
                    bit.update(v[x].s+1,1);
                    his.pb(v[x].s+1);
                }
                tmp.pb(v[x]);
                x++;
            }
            else{
              
                if(v[y].t==1){
                   
                    ans+=bit.query(v[y].s);
                }
                tmp.pb(v[y]);
                y++;
            }

        }
        while(x<=m){
            tmp.pb(v[x]);
            x++;
        }
        while(y<=r){
            if(v[y].t==1){
                ans+=bit.query(v[y].s);
            }

            y++;
        }
        for(lli z: his){
            bit.update(z,-1);
        }
        for(lli i=0; i<tmp.size(); ++i){
            v[l+i]=tmp[i];
        }
    }
}

void centroid_desc (lli x, lli n){
    lli centroid=get_centroid(x, get_sizes(x,-1), -1);
    x=centroid;
    //deb(x);
    vector<Query> v;
    Query aux ={0,0,0,0};
    v.pb(aux);
    aux={L,W,0,1};
    v.pb(aux);
    lli cont=1;
    for(auto a: adj[x]){
        lli y=a.first;
        if(is_rem[y]) continue;
        lli d=a.second;
        dfs(y,v,x,1,d,cont);
        cont++;
    }

    sort(v.begin(), v.end(), customComparator);
    
    resolver(0,v.size()-1, v);
    
    is_rem[x]=true;
    for(auto a: adj[x]){
        lli y=a.first;
        if(is_rem[y]) continue;
        centroid_desc(y,n);
    }
}


void solve(){
    lli n;
    cin>>n>>L>>W;
    bit.init(n);
    adj.resize(n+1);
    sz.resize(n+1,0);
 is_rem.resize(n+1,0);
 for(lli i=0; i<n-1; ++i){
    lli p,w;
    cin>>p>>w;
    adj[i+2].pb({p,w});
    adj[p].pb({i+2,w});
 }
 centroid_desc(1,n);
 cout<<ans<<endl;
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}