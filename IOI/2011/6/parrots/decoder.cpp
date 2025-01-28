#include "decoder.h"
#include "decoderlib.h"
#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;


void decode(int N, int L, int X[])
{
  vector<int> count (256,0); 
  for(int i=0; i<L; ++i){
    count[X[i]]++;
  }
  if(count[255]>=4){
    count[255]-=4;
        vector<int> ans (N,0);
   for(int i=0; i<N; ++i){
    ans[i]=(3-count[4*i])+4*(3-count[4*i+1])+16*(3-count[4*i+2])+64*(3-count[4*i+3]);
  }
  for(int i=0; i<N; ++i){
 //  deb(ans[i]);
    output(ans[i]);
  }
  }
  else{
  vector<int> ans (N,0);
  for(int i=0; i<N; ++i){
    ans[i]=count[4*i]+4*count[4*i+1]+16*count[4*i+2]+64*count[4*i+3];
  }
  for(int i=0; i<N; ++i){
 //  deb(ans[i]);
    output(ans[i]);
  }
  }

}
