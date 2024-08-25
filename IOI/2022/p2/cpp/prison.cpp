#include "prison.h"
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

std::vector<std::vector<int>> devise_strategy(int n) {
  vector<vector<int>> ans (25+1, vector<int> (n+1,0));
  
  for(int i=1; i<=n; ++i){
    int val=0;
    if( ( i>> 12 )& 1) val+=2;
    if( ( i>> 11 )& 1) val+=1;
    ans[0][i]=22+val;
  }
  for(int x=5; x>=0; --x){
    
    for(int j=2; j<6; ++j){
      ans[4*x+j][0]=x%2;
      for(int i=1; i<=n; ++i){
          int val=0;
        if( ( i>> 2*(x+1) )& 1) val+=2;
        if( ( i>> (2*x+1) )& 1) val+=1;
        val+=2;
        if(val==j){
          if(x==0){
            ans[4*x+j][i]=1;
          }
          else{
          int val=0;
          if( ( i>> 2*(x) )& 1) val+=2;
          if( ( i>> (2*x-1) )& 1) val+=1;
          ans[4*x+j][i]=4*(x-1)+val+2;
          }
        }
        else{
          if(val<j){
            if(x%2){
             ans[4*x+j][i]=-2;
            }
            else{
              ans[4*x+j][i]=-1;
            }
          }
          else{
            if(x%2){
             ans[4*x+j][i]=-1;
            }
            else{
              ans[4*x+j][i]=-2;
            }
          }
        }
    }
    } 
  }
  ans[1][0]=0;
  for(int i=1; i<=n; ++i){
    if(i%2){
      ans[1][i]=-2;
    }
    else{
      ans[1][i]=-1;
    }
  }
  return ans;
}
