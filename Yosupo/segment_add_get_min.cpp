#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;




struct line{
    lli m;
    lli b;
    lli eval (lli x){
        return m*x+b;
    }
    ld intersect (line l){
        return (ld) (l.b-b)/(m-l.m);
    }

};

lli mid (lli l, lli r){
    return (l+r-1)/2;
}
vector<line> v;
struct lichao{
    lli l,r;
    lichao *left, *right;
    lli ind;
    lichao(lli a, lli b): l(a), r(b){
      ind=-1;
      left=nullptr;
      right=nullptr;
    }

    void add(lli id, lli L, lli R){
        if(R<l || r<L) return;
        if(L<=l && r<=R){
            update(id);
            return;
        }
        if(l==r) return;
        if(!left){
            lli m=mid(l,r);
            left=new lichao(l,m);
            right=new lichao(m+1,r);
        }
        left->add(id, L, R);
        right->add(id, L,R);
    }

    void update(lli id){
        if(ind==-1){
            ind=id;
            return;
        }
        lli a,b,c,d;
        lli m=mid(l,r);
        a=v[ind].eval(l);
        b=v[id].eval(l);
        c=v[ind].eval(m);
        d=v[id].eval(m);
        if(l==r){
            if(b<a){
                ind=id;
            }
            return;
        }
        if(c<=d){
            if(a<=b){
                if(!left){
                    left=new lichao(l,m);
                    right=new lichao(m+1,r);
                }
                right->update(id);
            }
            else{
                if(!left){
                    left=new lichao(l,m);
                    right=new lichao(m+1,r);
                }
                left->update(id);
            }
        }
        else{
            if(a<=b){
                if(!left){
                    left=new lichao(l,m);
                    right=new lichao(m+1,r);
                }
                left->update(ind);
                ind=id;
            }
            else{
                 if(!left){
                    left=new lichao(l,m);
                    right=new lichao(m+1,r);
                }
                right->update(ind);
                ind=id;
            }
        }
    }

    lli query(lli p){
        lli aux=-1;
        if(left){
            lli m=mid(l,r);
            if(p<=m){
                aux=left->query(p);
            }
            else{
                aux=right->query(p);
            }
        }
        if(aux==-1){
            return ind;
        }
        if(ind==-1) return aux;
        if(v[aux].eval(p) >=v[ind].eval(p)) return ind;
        return aux;
    }

};

void solve(){
  lichao tree (-1e9, 1e9);
  lli n,q;
  cin>>n>>q;
  for(lli i=0; i<n; ++i){
    lli l,r,a,b;
    cin>>l>>r>>a>>b;
    v.pb({a,b});
    tree.add(v.size()-1, l, r-1);
  }  
  while(q--){
    lli type;
    cin>>type;
    if(type==0){
        lli l,r,a,b;
        cin>>l>>r>>a>>b;
        v.pb({a,b});
        tree.add(v.size()-1, l, r-1);
    }
    else{
        lli p;
        cin>>p;
        lli ind=tree.query(p);
        if(ind==-1){
            cout<<"INFINITY"<<endl;
        }
        else{
            lli val=v[ind].eval(p);
            cout<<val<<endl;
        }
    }
  }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}