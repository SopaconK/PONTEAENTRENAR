#include "werewolf.h"
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> check_validity(int N, vector<int> X, vector<int> Y,
                                vector<int> S, vector<int> E,
                                vector<int> L, vector<int> R) {
  int Q=S.size();
  int M=X.size();
  vector<int> ans;
  for(int ind=0; ind <Q; ++ind){
    vector<bool> vis(2*N, 0);
    int l=L[ind];
    int r=R[ind];
    vector<vector<int>> adj (2*N);
    for(int i=0; i<M; ++i){
      if(X[i]>=l && Y[i]>=l){
        adj[X[i]].pb(Y[i]);
        adj[Y[i]].pb(X[i]);
      }
      if(X[i]<=r && Y[i]<=r){
        adj[X[i]+N].pb(Y[i]+N);
        adj[Y[i]+N].pb(X[i]+N);
      }
    }
    for(int i=l; i<=r; ++i){
      adj[i].pb({i+N});
    }
    queue<int> q;
    q.push(S[ind]);
    vis[S[ind]]=true;
    while(!q.empty()){
      int x=q.front();
      q.pop();
      for(int y: adj[x]){
        if(!vis[y]){
          vis[y]=true;
          q.push(y);
        }
      }
    }
   

    ans.pb(vis[E[ind]+N]);
  }
  return ans;
}
