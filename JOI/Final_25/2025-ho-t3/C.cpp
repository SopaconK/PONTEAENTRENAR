#include<bits/stdc++.h>
using namespace std;
using lli=int;
using ld=long double;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'


struct segtree{
    lli l,r;
    segtree *left, *right;
    lli val=0;
    lli aux=0;
    segtree(lli a, lli b): l(a), r(b){
        if(l==r){
            left=right=NULL;
            val=0;
        }
        else{
            lli m=(l+r)/2;
            left=new segtree(l, m);
            right=new segtree(m+1,r);
            val=0;
        }
    }

    void upd(lli a, lli b, lli x){
  if(b<l || r<a){

            return;
        }
        if(l==r){
            aux=max(aux,x);
            val=max(val, aux);
            aux=0;
            return;
        }
        if(a<=l && r<=b){
            aux=max(aux, x);
            val=max(val, aux);
            return;
        }

        val=max(val, aux);
        left->aux=max(left->aux, aux);
        right->aux=max(right->aux, aux);

        aux=0;
        left->upd(a,b,x);
        right->upd(a,b,x);

        val=max(left->val, right->val); 

    }

    lli query(lli a){
         val=max(val, aux);
        if(l==r){
            return val;
        }
       
        left->aux=max(left->aux, aux);
        right->aux=max(right->aux, aux);

        aux=0;
        lli m=(l+r)/2;
        if(a<=m) return left->query(a);
        return right->query(a);   
    }
};


vector<lli> dis;

struct segtree2{
       lli l,r;
    segtree2 *left, *right;
    lli val=2e9;
    segtree2(lli a, lli b): l(a), r(b){
        if(l==r){
            left=right=NULL;
            val=dis[l];
        }
        else{
            lli m=(l+r)/2;
            left=new segtree2(l, m);
            right=new segtree2(m+1,r);
            val=min(left->val, right->val);
        }
    }

    lli query(lli a, lli b){

        if(a<=l && r<=b) return val;
        if(r<a || b<l) return 2e9;
        return min(left->query(a,b), right->query(a,b));
    }


};
 vector<lli> regreso;
lli r;
lli binaria(lli x){
    lli l=0;
//    deb(x);
    lli op=0;
    while(l<r-1){
        lli m=(l+r)/2;
        if(regreso[m]==x) return m;
        if(regreso[m]<x){
            l=m+1;
        }
        else{
            r=m;
        }
        op++;
       
   //     assert(op<1000);
    }
    if(regreso[l]<x) l=r;
    return l;
}

void solve(){
    lli n,m,p;
    cin>>n>>m>>p;
    set<lli> comp;
    vector<vector<lli>> ady (n);
    for(lli i=0; i<m; ++i){
        lli a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        ady[b].pb(c);
        comp.insert(c-1);
        comp.insert(c);
        comp.insert(c+1);
    }
    lli q;
    cin>>q;
    vector<pair<pair<lli,lli>, lli>> queries;
    for(lli i=0; i<q; ++i){
        lli a,b,c;
        cin>>a>>b>>c;
        queries.pb({{a,b},c});
        comp.insert(a);
        comp.insert(b);
        comp.insert(a-1);
        comp.insert(a+1);
        comp.insert(b-1);
        comp.insert(b+1);
    }
    lli cont=1;
    unordered_map<lli,lli> mp;
   
    regreso.pb(0);
    for(lli x: comp){
        mp[x]=cont;
        regreso.pb(x);

        cont++;
    }
    r=regreso.size();
    segtree *tree=new segtree(0, cont+5);

    for(lli i=1;i<n; ++i){
    
        for(lli j=0; j<ady[i].size(); ++j){
            ady[i][j]=mp[ady[i][j]];
        }
        ady[i].pb(0);

        sort(ady[i].begin(), ady[i].end()); //chance esto
        for(lli j=1; j<ady[i].size(); ++j){
            tree->upd(ady[i][j-1]+1, ady[i][j], ady[i][j]);
        }
        tree->upd(ady[i][ady[i].size()-1]+1, cont+4, 2e9);
    //
    }

    vector<lli> cosos (cont+5);
    for(lli i=0; i<cont+5; ++i){
        cosos[i]=tree->query(i);
    }
    dis.resize(cont+5, 2e9);
    for(lli i=0; i<cont+5; ++i){
        if(cosos[i]==2e9) break;
        if(regreso[i]<1) continue;
        dis[i]=regreso[cosos[i]]-regreso[i]+1;
    }

    segtree2 *arbol=new segtree2(0, cont+4);

    for(lli t=0; t<q; ++t){
        lli a=queries[t].first.first;
        lli b=queries[t].first.second;
        lli x=queries[t].second;
        lli u=mp[a];
        lli si=binaria(max(a-x,1));
  //      deb(si);
        lli god=arbol->query(si, u);
    //    deb(god);
        if(god<=(b-a+x+1)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}