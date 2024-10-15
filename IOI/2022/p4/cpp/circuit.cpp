#include "circuit.h"

#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

lli MOD=1000002022;

vector<lli> a;
vector<lli> b;
vector<vector<lli>> sons;
lli n;
void init(int N, int M, std::vector<int> P, std::vector<int> A) {
  a.resize(N+M);
  b.resize(N+M);
  sons.resize(N);
  for(lli i=1; i<P.size(); ++i){
    sons[P[i]].pb(i);
  }
  for(lli i=0; i<M; ++i){
    if(A[i]){
      a[N+i]=1;
      b[N+i]=0;
    }
    else{
      a[N+i]=0;
      b[N+i]=1;
    }
  }
  n=N;
}

int count_ways(int L, int R) {
  for(int i=L;i<=R; ++i ){
    swap(a[i], b[i]);
  }
  for(lli i=n-1; i>=0; --i){
    lli w=a[sons[i][0]];
    lli x=b[sons[i][0]];
    lli y =a[sons[i][1]];
    lli z=b[sons[i][1]];
    a[i]=2*w*y;
    a[i]%=MOD;
    a[i]+=w*z;
    a[i]%=MOD;
    a[i]+=x*y;
    a[i]%=MOD;
     b[i]=2*x*z;
    b[i]%=MOD;
    b[i]+=w*z;
    b[i]%=MOD;
    b[i]+=x*y;
    b[i]%=MOD;
  }
  return a[0];
}
