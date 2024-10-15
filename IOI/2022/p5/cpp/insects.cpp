#include "insects.h"

#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
vector<int> v;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int sum=0;
void bloque(int n){
 // deb(n);
   stack<pair<int,int>> sk;
  stack<int> sk2;
  for(int i=0; i<n; ++i){
    move_inside(sum+i);
 //   deb(press_button());
//    deb(sum+i);
    sk.push({press_button(),sum+i});
  }
  while(sk.top().first!=1){
    int x=sk.top().first;
 //   deb(x);
    while(sk.top().first!=1){
       if(sk.top().first!=x){
        sk2.pop();
        x=sk.top().first;
      }
      sk2.push(sk.top().second);
      
      move_outside(sk.top().second);
     
 //     deb(sk.top().second);
      sk.pop();
    }
    sk2.pop();
    while(!sk2.empty()){
      move_inside(sk2.top());
   //   deb(press_button);
      sk.push({press_button(), sk2.top()});
      sk2.pop();
    }
  }
 
  while(!sk.empty()){
    move_outside(sk.top().second);
    sk2.push(sk.top().second);
    v[sk2.top()]=sk2.top();
    sk.pop();
  }
  while(!sk2.empty()){
    int x=sk2.top();
    move_inside(x);
    for(int i=0; i<n; ++i){
      if(v[sum+i]!=-1) continue;
      move_inside(sum+i);
      int y=press_button();
      if(y==2){
        v[sum+i]=x;
      }
      move_outside(sum+i);
    }
    move_outside(x);

    sk2.pop();
  }
 
}

int min_cardinality(int n) {
  v.resize(n,-1);
 int sz=32;
 while(sum < n){
 // deb(sum);
  bloque(min(sz, n-sum));
  sum+=sz;
 }
   map<int,int> mp;
  for(int i=0; i<n; ++i){
    mp[v[i]]++;
  }
  for(int i=0; i<n; ++i){
    if(v[i]!=i) continue;
    pq.push({mp[v[i]], i});

  
  }
 vector<int> vis (n, -1);
 int ans=n;
 while(true){
  int x=pq.top().second;
  int y=pq.top().first;
  pq.pop();
  if(y >= ans ) return ans;
  if(vis[x]==-1){
   // deb(x);
    move_inside(x);
    vis[x]=x;
    for(int i=0; i<n; ++i){
      if(vis[i]!=-1) continue;
      if(v[i]==i){
        move_inside(i);
        if(press_button()==2){
          v[i]=x;
          mp[x]+=mp[i];
          vis[i]=true;
        }
        move_outside(i);
      }
    }
   
    y=mp[x];
    ans=min(ans,y);
    pq.push({y,x});
  }
 }
 return ans;
}
