#include "encoder.h"
#include "encoderlib.h"
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

void encode(int N, int M[])
{
  vector<int> ans1;
  vector<int> ans2;
  ans2.pb(255);
  ans2.pb(255);
  ans2.pb(255);
  ans2.pb(255);
  for(int i=0; i<N; ++i){
    for(int j=0; j<4; ++j){
      for(int x=0; x<(M[i])%4; ++x){
  //      deb(4*i+j);
        ans1.pb(4*i+j);
      }
      for(int x=(M[i]%4); x<3; ++x){
        ans2.pb(4*i+j);
      }
      M[i]/=4;
    }
  }
  if(ans1.size()<=ans2.size()){
    for(int y: ans1){
      send(y);
    }
  }
  else{
    for(int y: ans2){
      send(y);
    }
  }

  
}
