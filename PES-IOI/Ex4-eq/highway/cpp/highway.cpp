#include "highway.h"
#include<bits/stdc++.h>
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using namespace std;
using lli=long long;
void dfs(int x, int p, vector<int> &level, vector<vector<int>> &adj){
  for(int y: adj[x]){
    if(y==p) continue;
    level[y]=level[x]+1;
    dfs(y,x,level,adj);
  }
}

void find_pair(int N, vector<int> U, vector<int> V, int A, int B) {
  vector<int> level (N);
  level[0]=0;
  vector<vector<int>> adj (N);
  for(int i=0; i<N-1; ++i){
    adj[U[i]].pb(V[i]);
    adj[V[i]].pb(U[i]);
  }
  dfs(0,-1,level,adj);

  vector<vector<int>> arle(N);
  for(int i=0; i<N-1; ++i){
    
    int x=max(level[U[i]], level[V[i]]);

    arle[x].pb(i);

  }
  vector<int> aux (N-1,0);

  lli v=ask(aux);
  lli d=v/A;
//  deb(d);
  vector<lli> val;
  vector<lli> arista;
  for(lli x: arle[d]){
    arista.pb(x);
    if(level[U[x]]==d){
      val.pb(U[x]);
    }    
    else{
      val.pb(V[x]);
    }
  //  deb(arista[val.size()-1]);
//    deb(val[val.size()-1]);
  }
  lli l=0;
  lli r=val.size()-1;
  while(r-l>1){
    lli m=(r+l)/2;
    vector<int> aux (N-1,0);
    for(lli i=0; i<=m; ++i){
      aux[arista[i]]=1;
    }
    v=ask(aux);
    if(v==d*A){
      l=m+1;
    }
    else{
      r=m;
    }
  }
   vector<int> aux2 (N-1,0);
    for(lli i=0; i<=l; ++i){
      aux2[arista[i]]=1;
    }
    v=ask(aux2);
    if(v==d*A){
      l=r;
    }

  answer(0, val[l]);
}
