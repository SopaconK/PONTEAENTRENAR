#include "circuit.h"

#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

lli MOD=1000002022;

vector<lli> P;
vector<lli> mul;
vector<lli> normal;

vector<vector<lli>> sons;
lli n,m;

struct segtree{
  lli l,r;
  segtree *left, *right;
  lli sum=0;
  lli maxim=0;
  lli chng=0;
  segtree(lli a, lli b):l(a), r(b){
    if(l==r){
      sum=normal[l];
      maxim=mul[l];
      left=NULL;
      right=NULL;
    }
    else{
      lli m=(l+r)/2;
      left=new segtree(l, m);
      right=new segtree(m+1,r);
      sum=left->sum+right->sum;
      maxim=left->maxim+right->maxim;
      maxim%=MOD;
      sum%=MOD;
    //  deb(l);
      //deb(r);
     // deb(sum);
    //  deb(maxim);
    }

  }

  lli query(lli a, lli b){

    if(chng){
      if(!left){
        sum=maxim-sum+MOD;
      sum%=MOD;
      chng=0; 
      }
      else{
      left->chng++;
      left->chng%=2;
      right->chng++;
      right->chng%=2;
      sum=maxim-sum+MOD;
      sum%=MOD;
      chng=0;
      }
    }
   
  
    if(r<a || b<l) return sum;
    if(a<=l && r<=b){
      sum=maxim-sum+MOD;
      sum%=MOD;
   if(left){
    left->chng++;
      left->chng%=2;
      right->chng++;
      right->chng%=2;
   }
  //  deb(l);
   //   deb(r);
     // deb(sum);
     // deb(chng);

      return sum;
    }

      sum=left->query(a,b)+right->query(a,b);
      sum%=MOD;
//      deb(l);
//      deb(r);
  //    deb(sum);
      return sum;
    

  }
};

segtree* tree;

void dfs(int x){
 // deb(x);
  //eb(P[x]);  
 // deb(sons[x].size());
  if(sons[x].size()==0) return;
  lli Prod=sons[x].size();
  for(lli y: sons[x]){
    dfs(y);
   // deb(y);
//    deb(P[y]);
    Prod*=P[y];
  //  deb(Prod);
    Prod%=MOD;
  }
  P[x]=Prod;
}

void dfs2(int x){
  if(sons[x].size()==0) return;
  vector<lli> left(sons[x].size()+1,1);
  vector<lli> right(sons[x].size()+1,1);
  for(lli i=0; i<sons[x].size(); ++i){
    left[i+1]=left[i]*P[sons[x][i]];
    left[i+1]%=MOD;
  }
  for(lli i=sons[x].size()-1; i>=0; --i){
    right[i]=right[i+1]*P[sons[x][i]];
    right[i]%=MOD;
  }
  for(lli i=0; i<sons[x].size(); ++i){
      mul[sons[x][i]]=left[i]*right[i+1];
      mul[sons[x][i]]%=MOD;
  }
  for(lli y: sons[x]){
    dfs2(y);
  }
}

void dfs3(int x){
  normal[x]=mul[x];
 // deb(x);
 // deb(mul[x]);
  for(lli y: sons[x]){
    mul[y]*=mul[x];
    mul[y]%=MOD;
    dfs3(y);
  }
}

void init(int N, int M, std::vector<int> Par, std::vector<int> A) {
  P.resize(N+M+1,1);
  mul.resize(N+M+1,1);
  normal.resize(N+M+1,0);
 
  sons.resize(N+M);
  for(lli i=1; i<Par.size(); ++i){
    sons[Par[i]].pb(i);
  }
  dfs(0);
 // deb("hi");
  dfs2(0);
 // deb("shit");
  dfs3(0);
 // deb("Fak");
  n=N;
  m=M;
  for(lli i=0; i<N; ++i){
    normal[i]=0;
    mul[i]=0;
  }
  for(lli i=0; i<M; ++i){
    if(A[i]==0){
   
      normal[N+i]=0;
    }
  }
  
  //for(lli i=0; i<N+M; ++i){
    //cout<<mul[i]<<" ";
  //}
//  cout<<endl;
  tree=new segtree(N, N+M-1);
}

int count_ways(int L, int R) {
  lli ans=tree->query(L,R);
  //cout<<"---------------------"<<endl;
  return ans;
}
