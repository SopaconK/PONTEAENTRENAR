#include "islands.h"

#include <variant>
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
 map<pair<int,int>, vector<int>> mp;
stack<int> ans;
vector<bool> vis;
bool dob=false;
bool dfs (int x, int p, vector<vector<int>> &adj, vector<bool> &cero){
  //deb(x);
 // deb(p);
  ans.push(x);
  vis[x]=true;
  if(mp[{x, p}].size()>1){
    dob=true;
    return true;
  }
  if(cero[x] && p!=0) return true;
  for(int y:adj[x]){
    if(vis[y]) continue;
    if(dfs(y,x,adj,cero)) return true;
  }
  ans.pop();
  return false;
}
std::variant<bool, std::vector<int>> find_journey(
    int N, int M, std::vector<int> U, std::vector<int> V) {
 
  vector<vector<int>> adj (N);
  vector<bool> cero (N, 0);
  vis.resize(N,0);
  for(int i=0; i<M; ++i){

    mp[{U[i], V[i]}].pb(i);
    adj[U[i]].pb(V[i]);
    if(U[i]==0) cero[V[i]]=1;
    if(V[i]==0) cero[U[i]]=1;
    
  }
  if(dfs(0,-1,adj,cero)){
    
    vector<int> slv;
    vector<int> v;
    while(!ans.empty()){
      v.pb(ans.top());
      ans.pop();
    }
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size()-1; ++i){
      slv.pb(mp[{v[i], v[i+1]}][0]);
    }
  //  deb(dob);
    
    if(dob){
      int x=v[v.size()-2];
      int y=v[v.size()-1];
      slv.pb(mp[{y,x}][1]);
      slv.pb(mp[{x,y}][1]);
      for(int i=v.size()-2; i>=0; --i){
        slv.pb(mp[{v[i], v[i+1]}][0]);
      }
      return slv;
    }
    else{
      int x=v[v.size()-1];
      slv.pb(mp[{x,0}][0]);
      slv.pb(mp[{0,x}][0]);
       for(int i=v.size()-2; i>=0; --i){
     //   deb(i);
        slv.pb(mp[{v[i], v[i+1]}][0]);
      }
      slv.pb(mp[{x,0}][0]);
      slv.pb(mp[{0,x}][0]);
      return slv;
    }
  }
  return false;
}
