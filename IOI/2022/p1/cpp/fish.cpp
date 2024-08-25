#include "fish.h"

#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
lli cte=10;
long long max_weights(int n, int m, std::vector<int> x, std::vector<int> y,
                      std::vector<int> w) {

  vector<vector<lli>> mat (n, vector<lli> (cte,0));
  for(int i=0; i<m; ++i){
    mat[x[i]][y[i]+1]=w[i];
  }
  for(int i=0; i<n; ++i){
    for(int j=1; j<cte; ++j){
      mat[i][j]+=mat[i][j-1];
    }
  }
  vector<vector<lli>> v (cte, vector<lli> (cte,0));
  vector<vector<lli>> a (cte, vector<lli> (cte,0));
  for(int i=0; i<=9; ++i){
    for(int j=0; j<i; ++j){
      v[i][j]=mat[1][i]-mat[1][j];
    }
    for(int j=i+1; j<cte; ++j){
      v[i][j]=mat[0][j]-mat[0][i];
    }
  }
  for(int ind=2; ind<n; ++ind){
//    deb(ind);
    
    for(int i=0; i<cte; ++i){
 //     deb(i);
      for(int j=0; j<=i; ++j){
   //     deb(j);
        a[i][j]=0;
        for(int k=0; k<cte; ++k){
          
          a[i][j]=max(a[i][j], v[k][i]+mat[ind][i]-mat[ind][j]);
        }
      }
      for(int j=i+1; j<cte; ++j){
     //   deb(j);
        a[i][j]=0;
        for(int k=0; k<=i; ++k){
          a[i][j]=max(a[i][j], v[k][i]+mat[ind-1][j]-mat[ind-1][i]);
        }
        for(int k=i+1; k<=j; ++k){
          a[i][j]=max(a[i][j], v[k][i]+mat[ind-1][j]-mat[ind-1][k]);
        }
        for(int k=j+1; k<cte; ++k){
          a[i][j]=max(a[i][j], v[k][i]);
        }
      }
    }
    v=a;
  }
  lli ans=0;
  for(lli i=0; i<cte; ++i){
    for(lli j=0; j<cte; ++j){
      ans=max(ans, v[i][j] ); 
    }
  }
  return ans;
} 
