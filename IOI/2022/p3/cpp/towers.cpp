#include "towers.h"
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

vector<int> v;
struct segtree{
  int l, r, mx, p;
  segtree *left, *right;
  segtree(int a, int b): l(a), r(b){
    if(l==r){
      mx=v[l];
      p=l;
    }
    else{
      int m=(l+r)/2;
      left=new segtree(l, m);
      right=new segtree(m+1,r);
      if(left->mx >= right->mx){
        mx=left->mx;
        p=left->p;
      }
      else{
        mx=right->mx;
        p=right->p;
      }
    }

  }

  int query(int a, int b){
    if(r<a || b<l) return a;
    if(a<=l && r<=b) return p;
    int x=left->query(a,b);
    int y=right->query(a,b);
    if(v[x]>=v[y]) return x;
    return y;
  }
};
struct segtree2{
  int l, r, mn, p;
  segtree2 *left, *right;
  segtree2(int a, int b): l(a), r(b){
    if(l==r){
      mn=v[l];
      p=l;
    }
    else{
      int m=(l+r)/2;
      left=new segtree2(l, m);
      right=new segtree2(m+1,r);
      if(left->mn <= right->mn){
        mn=left->mn;
        p=left->p;
      }
      else{
        mn=right->mn;
        p=right->p;
      }
    }

  }

  int query(int a, int b){
    if(r<a || b<l) return a;
    if(a<=l && r<=b) return p;
    int x=left->query(a,b);
    int y=right->query(a,b);
    if(v[x]<=v[y]) return x;
    return y;
  }
};
segtree *tree;
segtree2 *tree2;
void init(int N, std::vector<int> H) {
  v=H;
  tree= new segtree(0, N-1);
  tree2= new segtree2 (0, N-1);
}

int solv(int L, int R, int D, int M){

  
  if(L>R) return 0;
  if(L==R){
    if(v[L]<=M) return 1;
    return 0;
  }
  int p=tree->query(L,R);
  int val=solv(L, p-1, D, v[p]-D)+solv(p+1, R, D, v[p]-D);
  int p2=tree2->query(L,R);
  if(v[p2]<=M) val=max(val,1);
  return val;

}

int max_towers(int L, int R, int D) {
   int p=tree->query(L,R);
   int val=solv(L, p-1, D, v[p]-D)+solv(p+1, R, D, v[p]-D);

    return max(1,val);
}
