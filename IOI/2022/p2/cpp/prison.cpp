#include "prison.h"
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

std::vector<std::vector<int>> devise_strategy(int n) {
  vector<vector<int>> s (25, vector<int> (n+1, 0));

  //0
  s[0][0]=0;
  for (lli i=1; i<=n; ++i){
    lli a=i>>11;
    a=a%4;
    s[0][i]=a+1;
  }
  // los demas
  for(lli i=1; i<=24; ++i){
    lli a=(i-1)/4;
    lli b=(i-1)%4;
    lli c=11-2*a;
    if(a%2==0){
      s[i][0]=1;
    
      for(lli j=1; j<=n; ++j){
        lli d=j>>c;
        d%=4;
        if(d>b){
          s[i][j]=-1;
        }
        else if(d<b){
          s[i][j]=-2;
        }
        else{
          if(a==5){
            if(j%2==1){
              s[i][j]=-1;
            }
            else{
              s[i][j]=-2;
            }
          }
          else{
            lli e=j>>(c-2);
            e%=4;
            s[i][j]=4*(a+1)+e+1;    
          }      
        }
      }
    }
    else{
            s[i][0]=0;
    
      for(lli j=1; j<=n; ++j){
        lli d=j>>c;
        d%=4;
        if(d>b){
          s[i][j]=-2;
        }
        else if(d<b){
          s[i][j]=-1;
        }
        else{
          if(a==5){
            if(j%2==1){
              s[i][j]=-2;
            }
            else{
              s[i][j]=-1;
            }
          }
          else{
            lli e=j>>(c-2);
            e%=4;
            s[i][j]=4*(a+1)+e+1;    
          }      
        }
      }
    }
  }

  return s;
}
